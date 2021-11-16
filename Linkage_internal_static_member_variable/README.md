Include a defined global variable in head
When a header file contains an already defined/initialized global variable or function, everything compiles.
When this header file is included in other files, linker reports an error 'multiple definition'.

When a header file contains a class/struct with already defined, i.e. (inline) initialized, members or functions, everything compiles.
When this header file is included in other files, linker doesn't report an error.

Is this a consequence of encapsulation?

