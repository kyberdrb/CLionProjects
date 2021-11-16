#include <iostream>
#include <typeinfo>
#include "typeid_decltype_nameMangling/TypeID_Decltype_NameMangling.h"
#include "auto_type/Auto.h"
#include "range_based_loop/Range_based_loop.h"
#include "nested_template_classes/Nested_Template_Classes.h"
#include "initialization_cpp_98/Initialization_CPP_98.h"
#include "initialization_cpp_11/Initialization_CPP_11.h"
#include "initializer_list/Initializer_List.h"
#include "object_initialization_default_delete/Object_Initialization_Default_Delete.h"
#include "lambda_expressions/Lambda_Expressions.h"
#include "delegating_constructors/Delegating_Constructors.h"
#include "elision_and_optimization/Elision_and_Optimization.h"
#include "type_casting/Type_Casting.h"
#include "perfect_forwarding/Perfect_Forwarding.h"
#include "bind/Bind.h"
#include "unique_pointer/Unique_Pointer.h"
#include "shared_pointer/Shared_Pointer.h"

int main() {
    TypeID_Decltype_NameMangling exercise_39;
    exercise_39.exercise();

    std::cout << std::endl;
    Auto exercise_40;
    exercise_40.exercise();

    std::cout << std::endl;
    Range_based_loop exercise_41;
    exercise_41.exercise();

    std::cout << std::endl;
    Nested_Template_Classes exercise_42_43_44;
    exercise_42_43_44.exercise();

    std::cout << std::endl;
    Initialization_CPP_98 exercise_45;
    exercise_45.exercise();

    std::cout << std::endl;
    Initialization_CPP_11 exercise_46;
    exercise_46.exercise();

    std::cout << std::endl;
    Initializer_List exercise_47;
    exercise_47.exercise();

    std::cout << std::endl;
    Object_Initialization_Default_Delete exercise_48;
    exercise_48.exercise();

    std::cout << std::endl;
    Lambda_Expressions exercise_49_50_51_52_53_54;
    exercise_49_50_51_52_53_54.exercise();

    std::cout << std::endl;
    Delegating_Constructors exercise_55;
    exercise_55.exercise();

    std::cout << std::endl;
    Elision_and_Optimization exercise_56_57_58_59;
    exercise_56_57_58_59.exercise();

    std::cout << std::endl;
    Type_Casting exercise_60_61_62;
    exercise_60_61_62.exercise();

    std::cout << std::endl;
    Perfect_Forwarding exercise_63;
    exercise_63.exercise();

    std::cout << std::endl;
    Bind exercise_64;
    exercise_64.exercise();

    std::cout << std::endl;
    Unique_Pointer exercise_65;
    exercise_65.exercise();

    std::cout << std::endl;
    Shared_Pointer exercise_66;
    exercise_66.exercise();

    return 0;
}