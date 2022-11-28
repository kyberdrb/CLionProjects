#include "string_examples.h"
#include "realloc_example.h"
#include "struct_examples.h"

//int main(int argc, char* argv[]) {
int main(int argc, char** argv) {
    print_text_directly();
    print_dynamically_allocated_text_examples();

    string_realloc_example();

    test_passing_stack_allocated_structs_by_value_and_pointer();

    return 0;
}