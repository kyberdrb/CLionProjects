// https://stackoverflow.com/questions/4762662/are-parentheses-around-the-result-significant-in-a-return-statement/25615981#25615981

// Parentheses around the return variable since the C++14 standard change the return type
//  to a reference, e.g. 'int&'
//  instead of a value, e.g 'int',
//  thus a changing the semantics.
// In previous C++ standards there is no difference between
//   return var1;
//  and
//   return (var1);
//  because both of them return a value,
//  thus, making these statements equivalent.

int var1 = 42;

// return type is int, same as decltype(var1)
decltype(auto) functionReturningByValue() {
    return var1;
}

// return type is int&, same as decltype((var1))
decltype(auto) functionReturningByReference() {
    return(var1);
}

int main() {
    int aValue = functionReturningByValue();
    int bValue = functionReturningByReference();

    // int& aReference = functionReturningByValue();   // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    const int& aReferenceConst = functionReturningByValue();
    int& bReference = functionReturningByReference();

    int&& aRvalueReference = functionReturningByValue();
    //int&& bRvalueReference = functionReturningByReference();    // error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’

    return 0;
}
