#include <iostream>
#include <memory>
#include <vector>
#include <sstream>

struct HtmlElement {
    std::string name, text;
    std::vector<HtmlElement> elements;
    const size_t indentationSpaces = 2;

    HtmlElement() = default;

    HtmlElement(std::string name, std::string text)
            :
            name(std::move(name)), text(std::move(text)) {}

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

struct HtmlBuilder {
    HtmlElement root;

    HtmlBuilder(const std::string& rootName) {
        root.name = rootName;
    }

    HtmlBuilder& addChild(
            const std::string& pName,
            const std::string& pText) {
        HtmlElement element{pName, pText};
        root.elements.emplace_back(element);
        return *this;
    }

    HtmlBuilder* addChild2(
            const std::string& pName,
            const std::string& pText) {
        HtmlElement element{pName, pText};
        root.elements.emplace_back(element);
        return this;
    }

    std::string str(int indent = 0) const {
        return root.str();
    }

    static HtmlBuilder build(const std::string& rootName) {
        return {rootName};
    }

    static std::unique_ptr<HtmlBuilder> build2(const std::string& rootName) {
        return std::make_unique<HtmlBuilder>(rootName);
    }

    explicit operator HtmlElement() const {
        return root;
    }
};

int main() {
    HtmlBuilder htmlBuilder{"ul"};
    htmlBuilder
        .addChild("li", "hello")
        .addChild("li", "world");
    std::cout << htmlBuilder.str() << std::endl;

    auto builder = HtmlBuilder
            ::build("ol")
            .addChild("li", "some")
            .addChild("li", "thing")
            .str();
    std::cout << builder << std::endl;

    HtmlElement&& element = static_cast<HtmlElement>(
            HtmlBuilder
            ::build("ol")
            .addChild("li", "foo")
            .addChild("li", "bar"));
    std::cout << element.str() << std::endl;

    auto builder2 = HtmlBuilder::build2("ul");
    builder2
        ->addChild2("li", "lili")
        ->addChild("li", "lolo");
    std::cout << builder2->str() << std::endl;

    return 0;
}