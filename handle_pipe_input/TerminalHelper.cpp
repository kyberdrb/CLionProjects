//
// Created by laptop on 7/16/24.
//

#include "TerminalHelper.h"

#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
#else
    #include <unistd.h>
#endif

bool TerminalHelper::isInputForwardedFromPipe() {
#ifdef _WIN32
    return !_isatty(0);
#else
    return !isatty(STDIN_FILENO);
#endif
}
