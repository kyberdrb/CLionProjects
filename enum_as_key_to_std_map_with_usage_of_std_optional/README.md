# `enum` as a key to `std::map`

Using `enum` and `enum class` (C++11 onwards) as a key to `std::map` .

In selected getters there is also usage of `std::optional` as a return value

## Sources

- ChatGPT

  I have a class defined as follows:

    ```
    class Class {
    public:
      enum Class_enum {
        OPTION_1,
        OPTION_2
      };
    };
    ```
    
    How can I use the class 'Class' as a key to a 'std::map'? How can I access the elements using the 'at()' function?
