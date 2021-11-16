#pragma once

#include <string>
#include <ostream>
#include <map>

class CodeBuilder {
private:
    std::string _class_name;
    std::map<std::string, std::string> _fields;

public:
    CodeBuilder(const std::string &class_name) {
        _class_name = class_name;
    }

    CodeBuilder& add_field(const std::string &name, const std::string &type) {
        _fields[name] = type;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os, const CodeBuilder &obj) {
        os << "class " << obj._class_name << "\n";
        os << "{" << "\n";

        for (const auto& field : obj._fields) {
            os << "  " << field.second << " " << field.first << ";\n";
        }

        os << "}" << "\n";
        return os.flush();
    }
};
