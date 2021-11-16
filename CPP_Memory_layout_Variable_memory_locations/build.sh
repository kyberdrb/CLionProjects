#/bin/bash

generate_debug_output() {
    EXECUTABLE=$1
    MESSAGE=$2
    echo
    echo '==============================================================='

    echo "$EXECUTABLE.cpp"
    echo
    echo "$MESSAGE"
    echo
    gcc -E $EXECUTABLE.cpp > $EXECUTABLE_preprocessed.cpp
    clang -cc1 -fdump-record-layouts $EXECUTABLE_preprocessed.cpp
    g++ -S -fverbose-asm -g $EXECUTABLE.cpp -o $EXECUTABLE.disassembled
    as -alhnd $EXECUTABLE.disassembled > $EXECUTABLE.disassembled.annotated
    g++ -o $EXECUTABLE $EXECUTABLE.cpp
    size $EXECUTABLE

    echo

    nm --demangle $EXECUTABLE > ${EXECUTABLE}_memory_configuration.txt
    nm --demangle $EXECUTABLE | grep -i globalNumber

    g++ -c -g -o $EXECUTABLE.o $EXECUTABLE.cpp
    objdump --source --reloc $EXECUTABLE.o > ${EXECUTABLE}_objdump.txt
}

clear

generate_debug_output main_basic

generate_debug_output main_global_var_uninitialized "looks like the 'bss' block is aligned to 8 bytes by hard"
generate_debug_output main_global_var_initialized_to_0
generate_debug_output main_global_var_initialized_to_other_value_than_0 "looks like the 'bss' block is aligned to 8 bytes by hard unless the 'data' sgment is involved... then it's aligned to 1 byte"

generate_debug_output main_two_global_vars_uninitialized
generate_debug_output main_two_global_vars_initialized_to_0
generate_debug_output main_two_global_vars_initialized_to_other_value_than_0

generate_debug_output main_global_static_var_uninitialized
generate_debug_output main_global_static_var_initialized_to_0
generate_debug_output main_global_static_var_initialized_to_other_value_than_0

generate_debug_output main_two_global_static_vars_uninitialized
generate_debug_output main_two_global_static_vars_initialized_to_0
generate_debug_output main_two_global_static_vars_initialized_to_other_value_than_0

generate_debug_output main_const_global_var_initialized_to_0
generate_debug_output main_const_global_var_initialized_to_other_value_than_0

generate_debug_output main_two_const_global_vars_initialized_to_0
generate_debug_output main_two_const_global_vars_initialized_to_other_value_than_0

generate_debug_output main_const_global_static_var_initialized_to_0
generate_debug_output main_const_global_static_var_initialized_to_other_value_than_0

generate_debug_output main_const_two_global_static_vars_initialized_to_0
generate_debug_output main_const_two_global_static_vars_initialized_to_other_value_than_0

generate_debug_output main_static_member_var_uninitialized "Optimized away"
generate_debug_output main_static_member_var_initialized_to_0
generate_debug_output main_static_member_var_initialized_to_other_value_than_0

generate_debug_output main_two_static_member_vars_uninitialized "Optimized away"
generate_debug_output main_two_static_member_vars_initialized_to_0
generate_debug_output main_two_static_member_vars_initialized_to_other_value_than_0

generate_debug_output main_const_static_member_var_uninitialized "Optimized away"
generate_debug_output main_const_static_member_var_initialized_to_0
generate_debug_output main_const_static_member_var_initialized_to_other_value_than_0

generate_debug_output main_const_two_static_member_vars_uninitialized "Optimized away"
generate_debug_output main_const_two_static_member_vars_initialized_to_0
generate_debug_output main_const_two_static_member_vars_initialized_to_other_value_than_0

generate_debug_output main_two_global_vars_in_custom_namespace_uninitialized
generate_debug_output main_two_global_vars_in_custom_namespace_initialized_to_0
generate_debug_output main_two_global_vars_in_custom_namespace_initialized_to_other_value_than_0

generate_debug_output main_two_global_static_vars_in_custom_namespace_uninitialized
generate_debug_output main_two_global_static_vars_in_custom_namespace_initialized_to_0
generate_debug_output main_two_global_static_vars_in_custom_namespace_initialized_to_other_value_than_0

generate_debug_output main_two_const_global_vars_in_custom_namespace_initialized_to_0
generate_debug_output main_two_const_global_vars_in_custom_namespace_initialized_to_other_value_than_0

generate_debug_output main_two_const_global_static_vars_in_custom_namespace_initialized_to_0
generate_debug_output main_two_const_global_static_vars_in_custom_namespace_initialized_to_other_value_than_0

generate_debug_output main_vars_in_anonymous_namespace

generate_debug_output main_string_literal
cat main_string_literal_objdump.txt | grep 'char\* string' -A2

generate_debug_output main_local_static_var
cat main_local_static_var_objdump.txt | grep static -A3 | tail -n4

generate_debug_output main_two_global_pointers
echo
./main_two_global_pointers
generate_debug_output main_two_static_global_pointers
echo
./main_two_static_global_pointers

generate_debug_output main_two_global_pointers_initialized_with_new
generate_debug_output main_two_static_global_pointers_initialized_with_new

rm a.out
rm .cpp

echo
