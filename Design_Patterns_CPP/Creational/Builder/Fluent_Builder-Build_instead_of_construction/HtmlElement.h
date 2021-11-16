//
// Created by laptop on 8/3/19.
//

#ifndef FLUENT_BUILDER_BUILD_INSTEAD_OF_CONSTRUCTION_HTMLELEMENT_H
#define FLUENT_BUILDER_BUILD_INSTEAD_OF_CONSTRUCTION_HTMLELEMENT_H

#include <string>
#include <vector>
#include <sstream>

class HtmlElement {
    friend class HtmlBuilder;

    std::string name, text;
    std::vector<HtmlElement> elements;
    const size_t indentationSpaces = 2;

    HtmlElement() = default;

    HtmlElement(std::string name, std::string text)
    : name(std::move(name)), text(std::move(text)) {}

public:
    std::string str(int indent = 0) const {
        std::ostringstream oss;
        std::string indentationSpace(indentationSpaces * indent, ' ');

        addOpeningTag(oss, indentationSpace);
        addText(oss, indent, text);
        addSubelements(oss, indent);
        addEnclosingTag(oss, indentationSpace);
        return oss.str();
    }

private:
    void addOpeningTag(
            std::ostringstream& oss,
            const std::string& indentationSpace) const {
        oss << indentationSpace << "<" << name << ">" << std::endl;
    }

    void addText(
            std::ostringstream& oss,
            int indent,
            std::string text) const {
        if (!text.empty()) {
            oss <<
                std::string(indentationSpaces*(indent + 1), ' ') <<
                text <<
                std::endl;
        }
    }

    void addSubelements(
            std::ostringstream& oss,
            int indent) const {
        for (const auto& element : elements) {
            oss << element.str(indent + 1);
        }
    }

    void addEnclosingTag(
            std::ostringstream& oss,
            const std::string& indentationSpace) const {
        oss << indentationSpace << "</" << name << ">" << std::endl;
    }
};

#endif //FLUENT_BUILDER_BUILD_INSTEAD_OF_CONSTRUCTION_HTMLELEMENT_H
