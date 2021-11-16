#include <stdio.h>
#include <assert.h>

struct ReturnValue {
    bool b;
    int k;
};

ReturnValue evaluateLogicalExpression();

int main() {
    int i = 5;
    int j = 3;
    int k = 0;
    bool b = false;

    k = 7;
    b = (i - 5) & (k = i - j);
    assert(b == 0);
    assert(k == 2);
    printf( "initialization:\n"
            "i = 5\n"
            "j = 3\n"
            "b = false\n"
            "k = 7 -> variable 'k' is set to value '7' after each computation of variable 'b'\n\n");
    printf("b = (i - 5) & (k = i - j):\tb = %d\tk = %d\n", b, k);
    printf( "\tRight operand will be evaluated and variable 'k' computed\n"
            "\tbecause operator '&' evaluates both operands with right-to-left associativity\n");

    printf("\n");

    k = 7;
    b = (i - 5) && (k = i - j);
    assert(b == 0);
    assert(k != 2);
    assert(k == 7);
    printf("b = (i - 5) && (k = i - j):\tb = %d\tk = %d\n", b, k);
    printf( "\tThe evaluation of the right operand and the computation of the variable 'k' will be skipped\n"
            "\tbecause operator '&&' skipps the evaluation of the right operand\n"
            "\twhen the left side is false, i.e. equals to 0\n");

    printf("\n");

    k = 7;
    b = (k = i - j) & (i - 5);
    printf("b = (k = i - j) &  (i - 5):\tb = %d\tk = %d\n", b, k);

    k = 7;
    b = (k = i - j) && (i - 5);
    printf("b = (k = i - j) && (i - 5):\tb = %d\tk = %d\n", b, k);

    printf("\n");

    k = 7;
    b = (i - 5) | (k = i - j);
    printf("b = (i - 5) |  (k = i - j):\tb = %d\tk = %d\n", b, k);

    k = 7;
    b = (i - 5) || (k = i - j);
    printf("b = (i - 5) || (k = i - j):\tb = %d\tk = %d\n", b, k);

    k = 7;
    b = (k = i - j) | (i - 5);
    printf("b = (k = i - j) |  (i - 5):\tb = %d\tk = %d\n", b, k);

    k = 7;
    b = (k = i - j) || (i - 5);
    printf("b = (k = i - j) || (i - 5):\tb = %d\tk = %d\n", b, k);

    ReturnValue rv;
    rv = evaluateLogicalExpression();
    printf("%d; %d\n", rv.b, rv.k);

    return 0;
}

ReturnValue evaluateLogicalExpression() {
    ReturnValue returnValue;
    int i = 5;
    int j = 3;
    int k = 7;
    bool b = (k = i - j) || (i - 5);
    returnValue.b = b;
    returnValue.k = k;
    return returnValue;
}
