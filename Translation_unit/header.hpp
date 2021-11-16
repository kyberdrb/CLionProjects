#pragma once

#define VALUE 5

// ifndef VALUE => dead code - the code will never be generated because the VALUE macro is defined above
// ifdef VALUE => ifdef directive unnecessary - the code will be always generated because the VALUE macro is defined above
#ifndef VALUE
struct Foo { private: int ryan; };
#endif

int strlen(const char* string);
