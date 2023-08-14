#include <iostream>

void reverse_buffer(char* buffer, uint16_t length) {
    char* head_ptr = &buffer[0];
    char* tail_ptr = &buffer[length - 1];

    //while ( head_ptr > tail_ptr ) {
    while ( tail_ptr > head_ptr ) {
        char head = *head_ptr;
        char tail = *tail_ptr;
        *head_ptr = tail;
        *tail_ptr = head;
        head_ptr++;
        tail_ptr--;
    }
}

int main() {
    //"Hello, World!"
    char buffer[14] = {
        'H',
        'e',
        'l',
        'l',
        'o',
        ',',
        ' ',
        'W',
        'o',
        'r',
        'l',
        'd',
        '!',
        '\0'
    };

    std::cout << buffer << std::endl;

    char charBefore = buffer[1];
    buffer[1] = 'E';
    std::cout << buffer << std::endl;
    buffer[1] = charBefore;
    std::cout << buffer << std::endl;

    reverse_buffer(buffer, 13);

    std::cout << buffer << std::endl;

    reverse_buffer(buffer, 13);
    std::cout << buffer << std::endl;

    char buffer2[] = {
        'B',
        'y',
        'e',
        '!',
        '\0'
    };

    std::cout << buffer2 << std::endl;
    reverse_buffer(buffer2, 4);
    std::cout << buffer2 << std::endl;
    reverse_buffer(buffer2, 4);
    std::cout << buffer2 << std::endl;

    return 0;
}
