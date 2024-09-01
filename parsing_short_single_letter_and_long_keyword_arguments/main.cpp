#include <iostream>
#include <sstream>

#include <getopt.h>
#include <cstring>
void parseArgumentsCstyle(int argc, char* argv[]);

#include <unordered_map>
void parseArgumentsCPPstyle(int argc, char**& argv);
// Function to parse command-line arguments
std::unordered_map<std::string, std::string> parseArguments(int argc, char* argv[], const std::unordered_map<std::string, bool>& optionsWithValues);

void print_usage();

int main(int argc, char *argv[]) {
    std::cout << "parseArgumentsCstyle" << std::endl;
    parseArgumentsCstyle(argc, argv);

    std::cout << std::endl;

    std::cout << "parseArgumentsCPPstyle" << std::endl;
    parseArgumentsCPPstyle(argc, argv);

    return 0;
}

void parseArgumentsCstyle(int argc, char* argv[]) {
    int option = -1;

    // Define long options
    struct option long_options[] = {
        {"precision", required_argument, nullptr, 'p'}, // when 'required_argument' has an empty value, the 'getopt_long' prints error message 'option requires an argument -- 'p''
        {"nopadding", no_argument, nullptr, 'd'},
        {"help", no_argument, nullptr, '?'},
        {nullptr, 0, nullptr, 0}
    };

    int option_index = 0;
    // Process options
    while ((option = getopt_long(
            argc,
            argv,
            "p:d?", // all available short/single-letter options need to be listed here to prevent error "invalid option -- '?'"
            long_options,
            &option_index)) != -1)
    {
        switch (option) {
            case 'p':
                std::cout << "precision: " << optarg << std::endl;
                break;
            case 'd':
                std::cout << "nopadding: padding disabled" << std::endl;
                break;
            case '?':
                std::cout << "help invoked" << std::endl;
                print_usage();
                break;
            default:
                std::cerr << "Unknown option: " << option << std::endl;
                print_usage();
                break;
        }
    }

    // Process any remaining arguments (non-option arguments)
    while (optind < argc) {
        std::cout << "Non-option argument: " << argv[optind++] << std::endl;
    }
}

void parseArgumentsCPPstyle(int argc, char**& argv) {
    // Define options and whether they expect a value
    std::unordered_map<std::string, bool> optionsWithValues = {
            {"p", true},
            {"precision", true},
            {"d", false},
            {"nopadding", false}
    };

    auto args = parseArguments(argc, argv, optionsWithValues);

    // Example usage of parsed arguments
    if (args.find("p") != args.end() || args.find("precision") != args.end()) {
        std::string precision = args.find("p") != args.end() ? args["p"] : args["precision"];
        std::cout << "precision: " << precision << std::endl;
    }

    if (args.find("d") != args.end() || args.find("nopadding") != args.end()) {
        std::cout << "nopadding: padding disabled" << std::endl;
    }

    if (args.find("?") != args.end() || args.find("help") != args.end()) {
        std::cout << "help invoked" << std::endl;
        print_usage();
    }

    if (args.find("nonoptional_arguments") != args.end()) {
        std::cout << "non-optional arguments" << std::endl;
        std::cout << args.at("nonoptional_arguments") << std::endl;
    }
}

// Function to parse command-line arguments
std::unordered_map<std::string, std::string> parseArguments(int argc, char* argv[], const std::unordered_map<std::string, bool>& optionsWithValues) {
    std::unordered_map<std::string, std::string> arguments;

    int32_t endOfOptionArguments = -1;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--") {
            std::cout << "option terminator '--' detected - handling non-option command line arguments" << std::endl;
            endOfOptionArguments = i;
            break;
        }

        if (arg[0] == '-') {
            std::string key;
            std::string value;

            if (arg[1] == '-') {
                // Handle keyword arguments (e.g., --precision, --padding)
                key = arg.substr(2);
            } else {
                // Handle single-letter arguments (e.g., -p, -d)
                key = arg.substr(1);
            }

            // Check if this option expects a value
            if (optionsWithValues.find(key) != optionsWithValues.end() && optionsWithValues.at(key)) {
                if (i + 1 < argc && argv[i + 1][0] != '-') {
                    value = argv[++i];
                } else {
                    std::cerr << "Option '" << arg << "' requires a value" << std::endl;
                }
            }

            arguments[key] = value;
        }
    }

//    if (endOfOptionArguments != -1) {
        std::cout << "Non-option arguments:" << std::endl;
        std::stringstream nonoptionArgumentsStream;
        for (int32_t nonoptionArgumentIndex = endOfOptionArguments + 1; nonoptionArgumentIndex < argc; ++nonoptionArgumentIndex) {
//            std::cout << argv[nonoptionArgumentIndex] << std::endl;
            nonoptionArgumentsStream << argv[nonoptionArgumentIndex] << ' ';
        }

        arguments.emplace("nonoptional_arguments", nonoptionArgumentsStream.str());
//    }

    return arguments;
}

void print_usage() {
    std::cout << "Usage: program [-p|--precision] PRECISION [-d|--nopadding]" << std::endl;
}
