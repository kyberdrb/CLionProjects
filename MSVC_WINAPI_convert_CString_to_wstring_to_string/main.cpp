#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <cstring>

int main(int argc, char** argv) {
#ifndef _WIN32
    return -1;
#endif

#ifndef _WIN64
    return -2;
#endif

    CString CStringVar = argv[1];
    if (CStringVar.IsEmpty() ) {
        CStringVar = L"CStringVar: Example text.";
    }
    std::cout << CStringVar << std::endl;
    std::wcout << CStringVar << std::endl;

    // Convert int to CString
    uint16_t indicator = 2;
    CStringVar.Format(_T("%02d"), indicator);
    std::cout << "CStringVar (cout) = " << CStringVar << std::endl;
    std::wcout << "CStringVar (wcout) = " << CStringVar << std::endl;

    indicator = 3;
    CStringVar.Format(L"%02d", indicator);
    std::cout << "CStringVar (cout) = " << CStringVar << std::endl;
    std::wcout << "CStringVar (wcout) = " << CStringVar << std::endl;

    // Convert integer to std::string
    std::stringstream sourceIndicatorStream;
    sourceIndicatorStream << std::setfill('0') << std::setw(2) << indicator;
    auto indicatorStr = sourceIndicatorStream.str();
    std::cout << "indicatorStr (cout) = " << indicatorStr << std::endl;
    // Convert std::string to CString
    CString destinationIndicatorCString = indicatorStr.c_str();
    std::cout << "destinationIndicatorCString (cout) = " << destinationIndicatorCString << std::endl;
    std::wcout << "destinationIndicatorCString (wcout) = " << destinationIndicatorCString << std::endl;

    // Convert integer to std::wstring
    std::wstringstream indicatorWStream;
    indicatorWStream << std::setfill(L'0') << std::setw(2) << indicator;
    auto indicatorWStr = indicatorWStream.str();
    std::wcout << "indicatorWStr (cout) = " << indicatorWStr << std::endl;
    // Convert std::wstring to CString
    destinationIndicatorCString = indicatorWStr.c_str();
    std::cout << "destinationIndicatorCString (cout) = " << destinationIndicatorCString << std::endl;
    std::wcout << "destinationIndicatorCString (wcout) = " << destinationIndicatorCString << std::endl;

    // Convert int to char array/buffer
    uint16_t bufferSize = 20;
    char indicatorCharBuf[bufferSize];
    snprintf(indicatorCharBuf, sizeof(indicatorCharBuf), "%02d", indicator);
    std::cout << "indicatorCharBuf=" << indicatorCharBuf << std::endl;
    // Convert char buf to std::string
    std::string destinationIndicatorString = indicatorCharBuf; // assuming presence of null terminator, as the char array is initialized to null terminators at declaration

    // Convert std::string to integer
    uint16_t destinationIndicator = stoi(destinationIndicatorString);

    // Convert std::wstring to integer
    uint16_t destinationIndicatorFromWstr = stoi(indicatorWStr);

    // Method 2 std::string/std::wstring to CString and v.v.
    std::stringstream stringStream;
    stringStream << CStringVar;
    std::cout << "stringStream.str()=" << stringStream.str().c_str() << std::endl;
    std::cout << "CStringVar=" << CStringVar << std::endl;
    std::wcout << "CStringVar=" << CStringVar << std::endl;

    // Convert CString to std::string via CT2CA - WINAPI-specific functionality
    CT2CA CStringVarZwischenString(CStringVar);
    std::string sourceStringStdStr = CStringVarZwischenString;
    std::cout << "sourceStringStdStr=" << sourceStringStdStr << std::endl;
    //std::wcout << "sourceStringStdStr=" << sourceStringStdStr << std::endl;

    // Convert CString to std::wstring - interchangeable
    std::wstring CStringVarWStdStr = CStringVar;
    //std::cout << "CStringVarWStdStr=" << CStringVarWStdStr << std::endl;
    std::wcout << "CStringVarWStdStr=" << CStringVarWStdStr << std::endl;
    //assert(strncmp(indicatorCharBuf, stringStream.str().c_str(), bufferSize) == 0);

    assert(strncmp(indicatorCharBuf, sourceStringStdStr.c_str(), bufferSize) == 0);
    //assert(strncmp(indicatorCharBuf, CStringVarWStdStr.c_str(), bufferSize) == 0);

    // Convert std::string to char buffer
    uint8_t destinationBuffer[bufferSize];
    assert(bufferSize > 0);
    auto bytesToCopy = std::min(sourceStringStdStr.size(), static_cast<size_t>(bufferSize - 1) );
    memcpy(destinationBuffer, sourceStringStdStr.c_str(), bytesToCopy);
    destinationBuffer[bytesToCopy] = '\0'; // Null-terminate the destination buffer if it's a string
    std::cout << "Destination buffer: " << destinationBuffer << std::endl;

    // Convert std::string to std::wstring
    std::string stringSource = "asdf";
    std::cout << "stringSource = " << stringSource << std::endl;
    std::wstring wideStringDestination = std::wstring(stringSource.begin(), stringSource.end());
    std::wcout << "wideStringDestination = " << wideStringDestination << std::endl;

    // Convert std::wstring to std::string
    std::wstring wideStringSource = L"asdf";
    std::string stringDestination = std::string(wideStringSource.begin(), wideStringSource.end());

    return 0;
}
