//
// Created by laptop on 8/3/19.
//

#ifndef FLUENT_BUILDER_BUILD_INSTEAD_OF_CONSTRUCTION_HTMLBUILDER_H
#define FLUENT_BUILDER_BUILD_INSTEAD_OF_CONSTRUCTION_HTMLBUILDER_H

#include "HtmlElement.h"

class HtmlBuilder {
    HtmlElement root;

public:
    explicit HtmlBuilder(const std::string& rootName) {
        root.name = rootName;
    }

    static HtmlBuilder create(const std::string& rootName) {
        return HtmlBuilder{rootName};
    }

    HtmlBuilder& addChild(
            const std::string& pName,
            const std::string& pText) {
        HtmlElement element{pName, pText};
        root.elements.emplace_back(element);
        return *this;
    }

    std::string str(int indent = 0) const {
        return root.str();
    }

    // operator for converting HtmlBuilder to HtmlElement can be ommited
//    explicit operator HtmlElement() const {
//        return root;
//    }

    HtmlElement build() {
        return root;
    }
};

#endif //FLUENT_BUILDER_BUILD_INSTEAD_OF_CONSTRUCTION_HTMLBUILDER_H
