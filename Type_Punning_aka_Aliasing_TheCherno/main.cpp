#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cassert>

// Type punning: https://en.wikipedia.org/wiki/Type_punning

int main() {
    printf("\n---------------------------------------------------\n");
    
    printf("sizeof(int) =\t\t%d\n", sizeof(int));
    printf("sizeof(double) =\t%d\n", sizeof(double));

    printf("---------------------------------------------------\n");

    assert(sizeof(int) != sizeof(double));

    int a = 50;
    printf("a =\t%d\n", a);

    double value = a;   // copy initialization - copy constructor invoked - implicit conversion
    printf("value =\t%f\n", value);

    double value2 = double(a);   // copy initialization - explicit conversion
    printf("value2 =\t%f\n", value2);

    // copy initialization with type punning
    double typePunnedValueWithC_StyleCast = *(double*)&a;   // type punning - casting a pointer of one type to a pointer of other type;
                                                            // and undefined behavior may apply.
                                                            // use the C-style cast only in C because it changes its meaning in C++ 
                                                            // under different circumstances (see 'C_style_cast_in_CPP_broken')

    // read/write from/to a type punned copy is safe
    // although we may experience undefined behavior
    // because when the destination type is larger than the source type
    // we will grab som memory outside of our source type which may contain random values
    // and lead to undefined behavior
    printf("typePunnedValueWithC_StyleCast =\t%f\n", typePunnedValueWithC_StyleCast);

    double typePunnedValueWithCppReinterpretCast = *reinterpret_cast<double*>(&a);
    printf("typePunnedValueWithCppReinterpretCast =\t%f\n", typePunnedValueWithCppReinterpretCast);

    double& typePunnedReference = *reinterpret_cast<double*>(&a);   // now we can reference the original type to a new type
                                                                    // if the destination type the same as the source type, the cast conforms to the strict aliasing rule;
                                                                    // if the destination type the different from the source type, the cast violates the strict aliasing rule

    // reading from a dereferenced type punned pointer is generally safe,
    // but when we write to a dereferenced type punned pointer (or to a type punned reference) and 
    // the destination type is larger than the source type, we may overwrite memory of another process
    // which leads to undefined behavior
    // Therefore, pay attention when you write to a dereferenced type punned pointer or to a type punned reference
    //typePunnedReference = 0.0,    // UB
    // or
    //double* typePunnedPointer = reinterpret_cast<double*>(&a);
    //*typePunnedPointer = 0.0;
    printf("typePunnedReference=\t%f\n", typePunnedValueWithCppReinterpretCast);    

    return 0;
}

