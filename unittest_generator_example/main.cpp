// Sources:
// - https://duckduckgo.com/?t=ffab&q=c%2B%2B+stream+uppercase&ia=web
// - https://duckduckgo.com/?t=ffab&q=c%2B%2B+multiple+variables+foreach&ia=web
// - https://stackoverflow.com/questions/2687392/is-it-possible-to-declare-two-variables-of-different-types-in-a-for-loop
// - https://duckduckgo.com/?t=ffab&q=c%2B%2B+int+hex+format&ia=web
// - https://stackoverflow.com/questions/5100718/integer-to-hex-string-in-c

#include <iostream>
#include <iomanip>

#include <array>

int main() {
    std::cout << "TCU - good\n";
    std::array<const uint8_t, 24> D_Tab_0xF170_38804_TCU_good {0x4E, 0x43, 0x52, 0x32, 0x31, 0x51, 0x34, 0x20, 0x54, 0x43, 0x4D, 0x49, 0x20, 0x20, 0x20, 0x20, 0x32, 0x32, 0x30, 0x32, 0x32, 0x33, 0x20, 0x20};
    uint8_t index;

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_good) {
        std::cout << "0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38804_TCU_good.at(index);
        ++index;

        if (index == 24) {
            break;
        }

        std::cout << ",";
    }
    std::cout << "\n";

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_good) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "], " << "0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38804_TCU_good.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << "0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38804_TCU_good.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_good) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "], " << (uint16_t) D_Tab_0xF170_38804_TCU_good.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << (uint16_t) D_Tab_0xF170_38804_TCU_good.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_good) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "]," << D_Tab_0xF170_38804_TCU_good.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << std::uppercase << D_Tab_0xF170_38804_TCU_good.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_good) {
        if (D_Tab_0xF170_38804_TCU_good.at(index) == ' ') {
            std::cout << "_";
        } else {
            std::cout << D_Tab_0xF170_38804_TCU_good.at(index);
        }

        ++index;

        if (index % 8 == 0) {
            std::cout << '\n';
        }
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_good) {
        if (D_Tab_0xF170_38804_TCU_good.at(index) == ' ') {
            std::cout << "_";
        } else {
            std::cout << D_Tab_0xF170_38804_TCU_good.at(index);
        }

        ++index;
    }
    std::cout << '\n';

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = -1;
    for (const auto element : D_Tab_0xF170_38804_TCU_good) {
        ++index;
        if (D_Tab_0xF170_38804_TCU_good.at(index) == ' ') {
            continue;
        }

        std::cout << D_Tab_0xF170_38804_TCU_good.at(index);
    }

    std::cout << "\n------------------------------------------\n\n";

    std::cout << "TCU - wrong\n";
    std::array<const uint8_t, 24> D_Tab_0xF170_38804_TCU_wrong {0x4E, 0x43, 0x52, 0x32, 0x31, 0x51, 0x34, 0x20, 0x54, 0x43, 0x49, 0x20, 0x20, 0x20, 0x20, 0x20, 0x32, 0x32, 0x30, 0x32, 0x32, 0x33, 0x20, 0x20};

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_wrong) {
        std::cout << "0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38804_TCU_wrong.at(index);
        ++index;

        if (index == 24) {
            break;
        }

        std::cout << ",";
    }
    std::cout << "\n";

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_wrong) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "], " << "0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38804_TCU_wrong.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << "0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38804_TCU_wrong.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_wrong) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "], " << (uint16_t) D_Tab_0xF170_38804_TCU_wrong.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << (uint16_t) D_Tab_0xF170_38804_TCU_wrong.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_wrong) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "]," << D_Tab_0xF170_38804_TCU_wrong.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << std::uppercase << D_Tab_0xF170_38804_TCU_wrong.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_wrong) {
        if (D_Tab_0xF170_38804_TCU_wrong.at(index) == ' ') {
            std::cout << "_";
        } else {
            std::cout << D_Tab_0xF170_38804_TCU_wrong.at(index);
        }

        ++index;

        if (index % 8 == 0) {
            std::cout << '\n';
        }
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38804_TCU_wrong) {
        if (D_Tab_0xF170_38804_TCU_wrong.at(index) == ' ') {
            std::cout << "_";
        } else {
            std::cout << D_Tab_0xF170_38804_TCU_wrong.at(index);
        }

        ++index;
    }
    std::cout << '\n';

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = -1;
    for (const auto element : D_Tab_0xF170_38804_TCU_wrong) {
        ++index;
        if (D_Tab_0xF170_38804_TCU_wrong.at(index) == ' ') {
            continue;
        }

        std::cout << D_Tab_0xF170_38804_TCU_wrong.at(index);
    }

    std::cout << "\n------------------------------------------\n\n";

    std::cout << "PE\n";
    std::array<const uint8_t, 24> D_Tab_0xF170_38805_PE {0x4E, 0x43, 0x52, 0x32, 0x32, 0x51, 0x31, 0x20, 0x45, 0x50, 0x49, 0x43, 0x46, 0x20, 0x20, 0x20, 0x32, 0x32, 0x30, 0x33, 0x31, 0x31, 0x20, 0x20};

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38805_PE) {
        std::cout << "0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38805_PE.at(index);
        ++index;

        if (index == 24) {
            break;
        }

        std::cout << ",";
    }
    std::cout << "\n";

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38805_PE) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "], 0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38805_PE.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << "0x" << std::hex << std::uppercase << (uint16_t) D_Tab_0xF170_38805_PE.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38805_PE) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "], " << (uint16_t) D_Tab_0xF170_38805_PE.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << (uint16_t) D_Tab_0xF170_38805_PE.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38805_PE) {
//        std::cout << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "], " << std::uppercase << D_Tab_0xF170_38805_PE.at(index) << ");" << std::endl;
//        ++index;

        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << std::uppercase << D_Tab_0xF170_38805_PE.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38805_PE) {
        if (D_Tab_0xF170_38805_PE.at(index) == ' ') {
            std::cout << "_";
        } else {
            std::cout << D_Tab_0xF170_38805_PE.at(index);
        }

        ++index;

        if (index % 8 == 0) {
            std::cout << '\n';
        }
    }

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = 0;
    for (const auto element : D_Tab_0xF170_38805_PE) {
        if (D_Tab_0xF170_38805_PE.at(index) == ' ') {
            std::cout << "_";
        } else {
            std::cout << D_Tab_0xF170_38805_PE.at(index);
        }

        ++index;
    }
    std::cout << '\n';

    std::cout << "...   ...   ...   ...   ...   ...\n";

    index = -1;
    for (const auto element : D_Tab_0xF170_38805_PE) {
        ++index;
        if (D_Tab_0xF170_38805_PE.at(index) == ' ') {
            continue;
        }

        std::cout << D_Tab_0xF170_38805_PE.at(index);
    }

    std::cout << "\n------------------------------------------\n\n";

    index = 0;
    for (int index = 0; index < 24; ++index) {
        std::cout << D_Tab_0xF170_38804_TCU_good.at(index) << " == " << D_Tab_0xF170_38805_PE.at(index) << " : " << (D_Tab_0xF170_38804_TCU_good.at(index) == D_Tab_0xF170_38805_PE.at(index)) << '\n';
    }

    std::cout << "\n------------------------------------------\n\n";

    index = 0;
    for (int index = 0; index < 24; ++index) {
        std::cout << D_Tab_0xF170_38804_TCU_wrong.at(index) << " == " << D_Tab_0xF170_38805_PE.at(index) << " : " << (D_Tab_0xF170_38804_TCU_wrong.at(index) == D_Tab_0xF170_38805_PE.at(index)) << '\n';
    }

    return 0;
}
