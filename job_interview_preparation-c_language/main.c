#include "string_examples.h"
#include "realloc_example.h"

int main(int argc, char** argv) {
    print_text_directly();
    print_dynamically_allocated_text_examples();

    string_realloc_example();

    return 0;
}