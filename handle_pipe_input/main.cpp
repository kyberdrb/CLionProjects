#include "TerminalHelper.h"

#include <iostream>

int main(int argc, char** argv) {
    std::string finalInput{"<default value>"};

#ifdef _DEBUG
	std::cout << "finalInput (init/default) = " << finalInput << std::endl;
#endif

#ifdef _DEBUG
	std::cout << "argc = " << argc << std::endl;
#endif

	if (2 == argc) {
		finalInput = argv[1];
#ifdef _DEBUG
        std::cout << "finalInput (forwarded from program arguments) = " << finalInput << std::endl;
#endif
	}

#ifdef _DEBUG
        std::cout << "isInputForwardedFromPipe() = " << TerminalHelper::isInputForwardedFromPipe() << std::endl;
#endif

    if (TerminalHelper::isInputForwardedFromPipe() ) {
        std::string pipeBuffer;
        while (std::getline(std::cin, pipeBuffer)) { // Read from stdin line by line
            std::cout << "Received from pipe: " << pipeBuffer << std::endl; // Process the input
            finalInput = std::move(pipeBuffer);
        }
    }

    std::cout << "finalInput = " << finalInput << std::endl;
    return 0;
}
