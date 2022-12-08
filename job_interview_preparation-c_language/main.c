#include "string_examples.h"
#include "realloc_example.h"
#include "struct_examples.h"
#include "shallow_deep_copy.h"
#include "algorithm_exercise.h"

//int main(int argc, char* argv[]) {
int main(int argc, char** argv) {
    print_text_directly();
    print_dynamically_allocated_text_examples();

    string_realloc_example();

    test_passing_stack_allocated_structs_by_value_and_pointer();
    test_passing_heap_allocated_structs_by_value_and_pointer();

    test_shallow_and_deep_copy_for_stack_allocated_instance();

    // static function - hidden from the outside - private function of the translation unit in which it's declared in
//    test_deep_copy_for_stack_allocated_instance();

    test_algorithm();

    return 0;
}