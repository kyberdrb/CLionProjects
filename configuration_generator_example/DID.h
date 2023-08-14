//
// Created by admin on 14. 6. 2023.
//

#pragma once

#include <ostream>

class DID {
public:
    DID(
        std::string id,
        std::string name,
        std::string lengthInBytes,
        std::string a2lElement);

    friend std::ostream& operator<<(std::ostream& out, const DID& did) {
        out << "<Did id="
            << "\"" << did._id << "\""
            << " name="
            << "\"" << did._name << "\""
            << " byteLength="
            << "\"" << did._lengthInBytes << "\""
            << " Ref="
            << "\"" << "Measurement.'" << did._a2lElement << "'" << "\""
            << "/>";
        return out;
    }

private:
    std::string _id;
    std::string _name;
    std::string _lengthInBytes;
    std::string _a2lElement;
};
