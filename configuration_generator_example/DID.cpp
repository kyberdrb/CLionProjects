//
// Created by admin on 14. 6. 2023.
//

#include "DID.h"

DID::DID(
        std::string id,
        std::string name,
        std::string lengthInBytes,
        std::string a2lElement)
:
        _id(id),
        _name(name),
        _lengthInBytes(lengthInBytes),
        _a2lElement(a2lElement)
{}
