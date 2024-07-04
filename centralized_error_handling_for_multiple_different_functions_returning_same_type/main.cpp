#include <iostream>

// Mock SDK functions
bool sdkFunction1(int a) {
    if (a > 0) return true;
    return false;
}

bool sdkFunction2(int a, double b) {
    if (a > 0 && b > 0.0) return true;
    return false;
}

// Primary template definition
template<typename Func, typename T1, typename T2>
struct CallSdkFunction {
    static bool call(const char* funcName, Func func, T1 arg1, T2 arg2) {
        bool result = func(arg1, arg2);
        if (!result) {
            std::cerr << "Error in: " << funcName << std::endl;
        }
        return result;
    }
};

// Specialization for one argument
template<typename Func, typename T1>
struct CallSdkFunction<Func, T1, void> {
    static bool call(const char* funcName, Func func, T1 arg1) {
        bool result = func(arg1);
        if (!result) {
            std::cerr << "Error in: " << funcName << std::endl;
        }
        return result;
    }
};

void testTemplatedCentralizedErrorHandlingFunction() {// Example usage of the callSdkFunction
    CallSdkFunction<bool(*)(int), int, void>::call("sdkFunction1", sdkFunction1, -1);          // Should print error
    CallSdkFunction<bool(*)(int, double), int, double>::call("sdkFunction2", sdkFunction2, 1, -2.0);  // Should print error
    CallSdkFunction<bool(*)(int), int, void>::call("sdkFunction1", sdkFunction1, 2);           // Should not print error
    CallSdkFunction<bool(*)(int, double), int, double>::call("sdkFunction2", sdkFunction2, 1, 2.0);   // Should not print error

}

#define CALL_SDK_FUNCTION(func, ...) ({ \
    bool result = func(__VA_ARGS__); \
    if (!result) { \
        std::cerr << "Error in: " << #func << " within function: " << __FUNCTION__ << std::endl; \
    } \
    result; \
})

bool testSdkFunction1() {
    return CALL_SDK_FUNCTION(sdkFunction1, -1);          // Should print error
}

bool testSdkFunction2() {
    return CALL_SDK_FUNCTION(sdkFunction2, 1, -2.0);     // Should print error
}

bool testSdkFunction1Success() {
    return CALL_SDK_FUNCTION(sdkFunction1, 2);           // Should not print error
}

bool testSdkFunction2Success() {
    return CALL_SDK_FUNCTION(sdkFunction2, 1, 2.0);      // Should not print error
}

void testCentralizedErrorHandlingMacroFunction() {// In C++98, it's not possible to directly deduce the function name from a function pointer in a macro. However, you can use a trick with the __FUNCTION__ macro, which expands to the name of the enclosing function. This doesn't give you the name of the function pointer being called, but it does give you the name of the function that contains the macro call.
    testSdkFunction1();
    testSdkFunction2();
    testSdkFunction1Success();
    testSdkFunction2Success();
}

// Macro for calling SDK function and checking the result
#define CALL_SDK_FUNCTION_WRAPPER(func, ...) ({ \
    bool result = func(__VA_ARGS__); \
    if (!result) { \
        std::cerr << "Error in: " << #func << " within function: " << __FUNCTION__ << std::endl; \
    } \
    result; \
})

void testCentralizedErrorHandlingMacroWrapperFunction() {// In C++98, it's not possible to directly deduce the function name from a function pointer in a macro. However, you can use a trick with the __FUNCTION__ macro, which expands to the name of the enclosing function. This doesn't give you the name of the function pointer being called, but it does give you the name of the function that contains the macro call.
    CALL_SDK_FUNCTION_WRAPPER(sdkFunction1, -1);          // Should print error
    CALL_SDK_FUNCTION_WRAPPER(sdkFunction2, 1, -2.0);     // Should print error
    CALL_SDK_FUNCTION_WRAPPER(sdkFunction1, 2);           // Should not print error
    CALL_SDK_FUNCTION_WRAPPER(sdkFunction2, 1, 2.0);      // Should not print error
}

int main() {
    testTemplatedCentralizedErrorHandlingFunction();
    std::cerr << std::endl;

    testCentralizedErrorHandlingMacroFunction();
    std::cerr << std::endl;

    testCentralizedErrorHandlingMacroWrapperFunction();
    std::cerr << std::endl;

    // Call macro function wrapper directly from main()
    CALL_SDK_FUNCTION_WRAPPER(sdkFunction1, -1);          // Should print error
    CALL_SDK_FUNCTION_WRAPPER(sdkFunction2, 1, -2.0);     // Should print error
    CALL_SDK_FUNCTION_WRAPPER(sdkFunction1, 2);           // Should not print error
    CALL_SDK_FUNCTION_WRAPPER(sdkFunction2, 1, 2.0);      // Should not print error

    return 0;
}
