#include <iostream>
#include <utility>
#include <vector>

struct Tag {
    std::string name, text;
    std::vector<Tag> children;
    std::vector<std::pair<std::string, std::string>> attributes;

    Tag(std::string name, std::string text) : name(std::move(name)), text(std::move(text)) {}
    Tag(std::string name, const std::vector<Tag> &children)
    :   name(std::move(name)), children(children) {}

    friend std::ostream& operator<<(std::ostream& os, const Tag& tag) {
        os << "<" << tag.name;

        if (tag.attributes.empty()) {
            os << ">" << std::endl;
        } else {
            os << " ";
            for (const auto& attribute : tag.attributes) {
                os << attribute.first << "=" << "\"" << attribute.second << "\"" << " ";
            }
        }

        if (!tag.text.empty()) {
            os << std::endl;
            os << tag.text << std::endl;
        }

        for (const auto& childTag : tag.children) {
            os << childTag << std::endl;
        }

        if (tag.attributes.empty()) {
            os << "</" << tag.name << ">";
        } else {
            os << "/>";
        }

        return os.flush();
    }
};

struct P : Tag {
    P(const std::string& text) : Tag("p", text) {}
    P(std::initializer_list<Tag> children)
    : Tag("p", children) {}
};

struct IMG : Tag {
    IMG(const std::string& url) : Tag("img", "") {
        attributes.emplace_back(std::make_pair("src", url));
    }

};

int main() {
    // Using uniform initialization i.e. nested constructors.
    // The constraints are modelled by the constructors.
    // Paragraph P can have other nested tags,
    // but image IMG can not. It can only have attributes.
    std::cout
    <<
        P {
            IMG {
                "http://pokemon.com/pikachu.png"
            }
        }
    <<
    std::endl;
    return 0;
}