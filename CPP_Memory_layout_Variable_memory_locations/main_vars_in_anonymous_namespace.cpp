namespace {
    float uninitializedGlobalNumber;    // In C++03, this one has external linkage
    float globalNumberInitToZero = 0;
    float globalNumberInitToOtherThanZero = 1;

    const float constGlobalNumberInitToZero = 0;
    const float constGlobalNumberInitToOtherThan0 = 1;

    static float uninitializedStaticGlobalNumber;
    static float staticGlobalNumberInitToZero = 0;
    static float staticGlobalNumberInitToOtherThanZero = 1;

    const static float constStaticGlobalNumberInitToZero = 0;
    const static float constStaticGlobalNumberInitToOtherThanZero = 1;

    extern int internallyLinkedFunctionForGlobalNumberDespiteExternKeyword() {    // has internal linkage despite 'extern'
        return 0; 
    }

    extern "C" int externallyLinkedFunctionForGlobalNumberIgnoring() {      // ignores linkage of namespace
        return 0;
    }
}

int (*p)() = internallyLinkedFunctionForGlobalNumberDespiteExternKeyword;  // ensure 'f' won't be optimized away

int main() {
    return 0;
}
