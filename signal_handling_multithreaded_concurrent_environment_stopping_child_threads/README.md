# Handing signal interrupts in POSIX compatible operating systems in multithreaded and concurrent environment

Stopping child threads with infinite loop safely

## Note
If a terminal application has global pointers to dynamically allocated memory and does not handle signals such as Ctrl+C [SIGINT], SIGTERM (the default signal for the 'kill' command), SIGQUIT (like SIGINT, but generates a coredump), or SIGABRT, then the destructors for these variables/classes will not be called, even if destructors are defined for these types/classes.

## TODOs

- implement signal handling for Windows platform

## Sources

- https://github.com/kyberdrb/CLionProjects/tree/main/signal_handling
- https://github.com/kyberdrb/CLionProjects/tree/main/animation-single_character_circular
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+keep+main+thread+alive+when+child+threads+are+running&ia=web&iax=qa
- http://www.modernescpp.com/index.php/c-core-guidelines-taking-care-of-your-child-thread/
- https://stackoverflow.com/questions/30672199/stdthread-how-to-make-main-thread-keep-running-and-children-branch-off
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+when+a+detached+thread+is+destructed&ia=web&iax=qa
- https://stackoverflow.com/questions/45685463/does-c-11-thread-automatically-destroy-after-detach
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+stop+all+threads+after+receiving+signal&ia=web
- https://codereview.stackexchange.com/questions/283622/safely-starting-and-stopping-a-thread-owned-by-a-class
- https://stackoverflow.com/questions/30002609/c-signal-and-threads#30005683
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+std%3A%3Athread&ia=web
- https://en.cppreference.com/w/cpp/thread/thread
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+std%3A%3Athread+std%3A%3Afunction&ia=web&iax=qa
- https://duckduckgo.com/?t=ffab&q=error%3A+no+match+for+call+to+%E2%80%98(std%3A%3Athread)+(void+(%26)())&ia=web&errorRetry=1
- https://stackoverflow.com/questions/12624271/c11-stdthread-giving-error-no-matching-function-to-call-stdthreadthread
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+wrap+std%3A%3Athread+class&ia=web
- https://codereview.stackexchange.com/questions/178328/implementation-of-a-generic-thread-safe-object-wrapper
- https://www.codeproject.com/Articles/1177478/Thread-Wrapper-CPP
- https://stackoverflow.com/questions/10998780/stdthread-calling-method-of-class
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+error%3A+no+match+for+call+to+%E2%80%98(std%3A%3Athread)&ia=web
- https://stackoverflow.com/questions/50317390/error-no-matching-function-for-call-to-stdthread
