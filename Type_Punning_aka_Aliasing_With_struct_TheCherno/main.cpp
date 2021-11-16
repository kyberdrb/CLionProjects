#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cassert>

// Type punning [from 7:08] : https://en.wikipedia.org/wiki/Type_punning

// In C, the struct consists only of its members and padding between them if necessary
// In C++, the class/struct consist only of its members, padding between memebers, member functions, 
// and vpointer - virtual pointer, if the class/struct contains at least one virtual function
struct Entity {
    int x, y;

    int* getPositions() {   // SOLUTION 1: ia method returning the address of the beginning member in the struct 
                            // in order to avoid type punning and breaking the strict aliasing rule
                            // Works only for members of the same type or size
        return &x;
    }
};

int main() {

    Entity e{5, 8};
    printf("Entity e:\n\tx = %d\n\ty = %d\n", e.x, e.y);
    printf("\n");

    printf("\n");

    int* members = reinterpret_cast<int*>(&e);  // type punning from Entity* to int* - strict aliasing rule violated
    int firstMember = members[0];
    int secondMember = members[1];  // this will work only when the struct has members of the same size
    printf( "Members of an instance of Entity accessed with type-punning...\n"
            "and breaking strict aliasing rule in the process :P\n");
    printf("\te.x =\t%d\n\te.y =\t%d\n", firstMember, secondMember);

    int* otherMembers = e.getPositions();   // SOLUTION 1 continuation
    firstMember = otherMembers[0];
    secondMember = otherMembers[1];  // this will work only when the struct has members of the same size
    printf( "Members of an instance of Entity accessed without type-punning...\n"
            "and conforming to the strict aliasing rule B)\n");
    printf("\te.x =\t%d\n\te.y =\t%d\n", firstMember, secondMember);

    printf("\n");

    int x = 0;
    x = e.x;
    printf("e.x =\t%d\n", x);

    x = *(int*) &e; // type punning from Entity* to int* with dereference - strict aliasing rule violated
    printf("e.x (first bytes of the struct punned) =\t%d\n", x);

    int y = 0;
    y = *(int*)((char*) &e + 4);    // type punning through char pointer is not a violation of strict aliasing rule
                                    // because char aliases all of the types
    printf("e.y (C-style cast) =\t%d\n", y);


    // SOLUTION 2: alias the members through the char pointer ('char*')
    // This solution still doesn't prevent undefined behavior 
    // when we overshoot the memory boundaries of the source type
    y = *reinterpret_cast<int*>((reinterpret_cast<char*>(&e) + 4));
    printf("e.y (two reinterpret casts on one line) =\t%d\n", y);

    char* yy = reinterpret_cast<char*>(&e) + 4;
    int yyy = *reinterpret_cast<int*>(yy);
    printf("e.y (separate reinterpret cast) =\t%d\n", yyy);

    yy = reinterpret_cast<char*>(&e) + sizeof(int);
    yyy = *reinterpret_cast<int*>(yy);
    printf("e.y (separate reinterpret cast with sizeof(int)) =\t%d\n", yyy);

    return 0;
}

