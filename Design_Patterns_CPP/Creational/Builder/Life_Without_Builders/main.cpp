#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string paragraphText = "hello";
    std::string htmlParagraph = "<p>";
    htmlParagraph += paragraphText;
    htmlParagraph += "</p>";
    std::cout << htmlParagraph << std::endl;

    std::vector<std::string> unnumberedListItems{ "hello", "word" };
    std::ostringstream oss;
    oss << "<ul>";
    for (const auto& item : unnumberedListItems) {
        oss << " <li>" << item << "</li> ";
    }
    oss << "</ul>";
    std::cout << oss.str() << std::endl;

    // String concatenation or stream insertion are neither scalable
    // nor object oriented approaches to creating a complicated object.
    // Solution is to use to use the Builder design pattern.

    return 0;
}