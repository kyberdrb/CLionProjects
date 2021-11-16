//
// Created by laptop on 7/24/19.
//

#ifndef CPP_11_NEW_FEATURES_LAMBDA_EXPRESSIONS_H
#define CPP_11_NEW_FEATURES_LAMBDA_EXPRESSIONS_H

#include <functional>

class Lambda_Expressions {
public:
    void exercise();

private:
    void test(void (*)());
    void testGreet(void (*)(const std::string&));
    void runDivide(double (*)(double, double));
    bool check(std::string&);
    void run(std::function<bool(std::string&)>);
};


#endif //CPP_11_NEW_FEATURES_LAMBDA_EXPRESSIONS_H
