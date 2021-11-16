Breaking external linkage

Scenario: Include a header file with an already defined function in multiple files, i.e. share a defined function in one header file in multiple other files. The function is after preprocessing defined not only in the header file, but in all files in which this header file has been included. This creates multiple definitions of the same function in translation units. And multiple definition of the same symbol (variable, function, class, struct) violate the ODR - One Definition Rule. Therefore, the code doesn't compile; the compilation fails at linking where the linker finds multiple definitions for one function in multiple translation units.

http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/
