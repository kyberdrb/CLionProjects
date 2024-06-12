#include <iostream>
#include <map>
#include <memory>

class ExampleClass {
public:
    ExampleClass() {
        this->fillMap();
    };

    std::wstring getValueOption1() const;
    std::wstring getValueOption2() const;
    std::optional<std::wstring> getValueOption3() const;
    std::optional<std::wstring> getValueOption4() const;

private:
    enum OPTIONS_ENUM {
        OPTION_1,
        OPTION_2
    };
    std::map<OPTIONS_ENUM, std::wstring> _optionsMap;

    enum OPTIONS_ENUM_CLASS {
        //OPTION_1, // clang-tidy: Redefinition of enumerator 'OPTION_1' - GCC: error: ‘OPTION_1’ conflicts with a previous declaration 'note: previous declaration ‘ExampleClass::OPTIONS_ENUM ExampleClass::OPTION_1’'
        OPTION_3,
        OPTION_4
    };
    std::map<OPTIONS_ENUM_CLASS, std::wstring> _optionsMapEnumClass;

    void fillMap();
};

void ExampleClass::fillMap() {
    this->_optionsMap.emplace(std::make_pair<>(OPTIONS_ENUM::OPTION_1, L"123"));
    this->_optionsMap.emplace(std::make_pair<>(OPTIONS_ENUM::OPTION_2, L"abc"));
    this->_optionsMapEnumClass.emplace(std::make_pair<>(OPTIONS_ENUM_CLASS::OPTION_3, L"456"));
//    this->_optionsMapEnumClass.emplace(std::make_pair<>(OPTIONS_ENUM_CLASS::OPTION_4, L"xyz"));
}

std::wstring ExampleClass::getValueOption1() const {
    try {
        return this->_optionsMap.at(OPTIONS_ENUM::OPTION_1);
    }
    catch (const std::out_of_range&) {
        return L"";
    }
}

std::wstring ExampleClass::getValueOption2() const {
    try {
        return this->_optionsMap.at(OPTIONS_ENUM::OPTION_2);
    }
    catch (const std::out_of_range&) {
        return L"";
    }
}

std::optional<std::wstring> ExampleClass::getValueOption3() const {
    try {
        return this->_optionsMapEnumClass.at(OPTIONS_ENUM_CLASS::OPTION_3);
    }
    catch (const std::out_of_range&) {
        return std::nullopt;
    }
}

std::optional<std::wstring> ExampleClass::getValueOption4() const {
    try {
        return this->_optionsMapEnumClass.at(OPTIONS_ENUM_CLASS::OPTION_4);
    }
    catch (const std::out_of_range&) {
        return std::nullopt;
    }
}

int main() {
    auto example = std::make_unique<ExampleClass>();
    std::wcout << example->getValueOption1() << std::endl;
    std::wcout << example->getValueOption2() << std::endl;
    std::wcout << *(example->getValueOption3() ) << std::endl;

    auto result = example->getValueOption4();
    std::wcout << "result.has_value(): " << result.has_value() << std::endl;
    if (!result.has_value()) {
        std::wcout << L"<element not found>" << std::endl;
    }

    if (!result) {
        result = L"<element not found>";
    }

    if (result.has_value()) {
        std::wcout << *result << std::endl;
    }

    auto anotherResult = example->getValueOption4().value_or(L"<element not found>");
    std::wcout << *result << std::endl;

    //std::wcout << *(example->getValueOption4() ) << std::endl; // undefined behavior when dereferencing std::nullopt

    return 0;
}
