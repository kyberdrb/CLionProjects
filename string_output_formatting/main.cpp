// Sources
// - https://duckduckgo.com/?t=ffab&q=c%2B%2B+formatting+output+in+columns&ia=web
// - https://stackoverflow.com/questions/2436004/how-do-i-correctly-organize-output-into-columns
// - https://duckduckgo.com/?t=ffab&q=c%2B%2B+stream+pad+string+left+right+columns&ia=web
// - https://duckduckgo.com/?t=ffab&q=c%2B%2B+cout+dynamic+padding+string&ia=web
// - https://stackoverflow.com/questions/15674097/output-aligned-columns
// - https://duckduckgo.com/?t=ffab&q=std+cout+align+to+columns&ia=web
// - https://stackoverflow.com/questions/1714515/how-can-i-pad-an-int-with-leading-zeros-when-using-cout-operator
// - https://duckduckgo.com/?t=ffab&q=c%2B%2B+std+cout+padding&ia=web

#include <iostream>

#include <iomanip>

int main() {
    std::cout << "Hello, World!" << std::endl;
    
    std::cout << std::setfill('0') << std::setw(5) << 25 << '\n';
    std::cout << std::setfill(' ') << std::setw(5) << 25 << '\n';

    //std::setfill('*');
    std::cout.fill('*');
    std::cout << -12345 << std::endl; // print default value with no field width
    std::cout << std::setw(10) << -12345 << std::endl; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << std::endl; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << std::endl; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << std::endl; // print internally justified

    std::cout << "XML_UT_TEST(Data_UT[0]," << "0x4E);" << '\n';
    std::cout << "XML_UT_TEST(Data_UT[12]," << "0x46);" << '\n';
    std::cout << "XML_UT_TEST(Data_UT[0]," << "  " << "0x4E);" << '\n';
    std::cout << "XML_UT_TEST(Data_UT[12]," << " " << "0x46);" << '\n';
    std::cout << std::setfill('*') << std::setw(25) << std::left << "XML_UT_TEST(Data_UT[0]," << "0x4E);" << '\n';
    std::cout << std::setfill('*') << std::setw(25) << std::left << "XML_UT_TEST(Data_UT[12]," << "0x46);" << '\n';

    std::array<const uint8_t, 24> Data_UT {0x4E, 0x43, 0x52, 0x32, 0x32, 0x51, 0x31, 0x20, 0x45, 0x50, 0x49, 0x43, 0x46, 0x20, 0x20, 0x20, 0x32, 0x32, 0x30, 0x33, 0x31, 0x31, 0x20, 0x20};
    std::cout << "0x" << std::hex << (uint16_t) Data_UT[2] << '\n';
    std::cout << "0x" << std::hex << (uint16_t) Data_UT [2] << '\n';
    std::cout << "0x" << std::hex << (uint16_t) Data_UT[ 2] << '\n';
    std::cout << "0x" << std::hex << (uint16_t) Data_UT[2 ] << '\n';
    std::cout << "0x" << std::hex << (uint16_t) Data_UT [ 2 ] << '\n';
    std::cout << "0x" << std::hex << (uint16_t) Data_UT     [     2     ] << '\n';

    std::cout << "XML_UT_TEST(Data_UT[" << std::dec << 0 << "]," << "0x" << std::hex << std::uppercase << (uint16_t) Data_UT.at(0) << ");" << std::endl;
    std::cout << "XML_UT_TEST(Data_UT[" << std::dec << 0 << std::setfill(' ') << std::setw(5) << std::left << "]," << "0x" << std::hex << std::uppercase << (uint16_t) Data_UT.at(0) << ");" << std::endl;
    std::cout << "XML_UT_TEST(Data_UT[" << std::dec << 0 << std::setfill(' ') << std::setw(5) << std::right << "]," << "0x" << std::hex << std::uppercase << (uint16_t) Data_UT.at(0) << ");" << std::endl;
    std::cout << "XML_UT_TEST(Data_UT[" << std::dec << 0 << "]," << std::setfill(' ') << std::setw(5) << std::right << "0x" << std::hex << std::uppercase <<  (uint16_t) Data_UT.at(0) << ");" << std::endl;
    std::cout << "XML_UT_TEST(Data_UT[" << std::dec << 12 << "]," << std::setfill(' ') << std::setw(5) << std::right << "0x" << std::hex << std::uppercase <<  (uint16_t) Data_UT.at(12) << ");" << std::endl;

    std::cout << "XML_UT_TEST(Data_UT[" << std::dec << 0 << std::setfill('*') << std::setw(25) << std::left << "]," << "0x" << std::hex << std::uppercase << (uint16_t) Data_UT.at(0) << ");" << std::endl;
    std::cout << "XML_UT_TEST(Data_UT[" << std::dec << 12 << std::setfill('*') << std::setw(25) << std::left << "]," << "0x" << std::hex << std::uppercase << (uint16_t) Data_UT.at(12) << ");" << std::endl;

    std::stringstream XML_UT_TEST_Data_UT_0{"XML_UT_TEST(Data_UT[0],"};
    std::cout << std::setfill('*') << std::setw(25) << std::left << XML_UT_TEST_Data_UT_0.str() << "0x4E);" << '\n';
    std::stringstream XML_UT_TEST_Data_UT_12{"XML_UT_TEST(Data_UT[,"};
    XML_UT_TEST_Data_UT_12 << 12 << "],";
    std::cout << std::setfill('*') << std::setw(25) << std::left << XML_UT_TEST_Data_UT_12.str() << "0x46);" << '\n';

    std::cout << std::endl;

    std::cout << std::setfill('*') << std::setw(25) << std::left << "XML_UT_TEST(Data_UT[0]," << "0x4E);" << '\n';
    std::cout << std::setfill('*') << std::setw(25) << std::left << "XML_UT_TEST(Data_UT[12]," << "0x46);" << '\n';

    std::cout << std::endl;

    std::stringstream xml_tag_0{"XML_UT_TEST(Data_UT[0],"};
    std::stringstream value_0{"0x4E);"};
    std::cout << std::setfill('*') << std::setw(25) << std::left << xml_tag_0.str() << value_0.str() << '\n';
    std::stringstream xml_tag_12;
    xml_tag_12 << "XML_UT_TEST(Data_UT[";
    xml_tag_12 << 12 << "],";
    std::stringstream value_12;
    value_12 << "0x" << 46 << ");";
    std::cout << std::setfill('*') << std::setw(25) << std::left << xml_tag_12.str() << value_12.str() << '\n';

    std::cout << std::endl;
    std::cout.fill(' ');

    uint8_t index = 0;
    for (const auto element : Data_UT) {
        std::stringstream xml_tag;
        xml_tag << "XML_UT_TEST(Data_UT[" << std::dec << (uint16_t) index << "],";
        std::cout << std::setw(25) << std::left << xml_tag.str();

        std::stringstream value;
        value << "0x" << std::hex << std::uppercase << (uint16_t) Data_UT.at(index) << ");";
        std::cout << value.str() << '\n';

        ++index;
    }

    return 0;
}
