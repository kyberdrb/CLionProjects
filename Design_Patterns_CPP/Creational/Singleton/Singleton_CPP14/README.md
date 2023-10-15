# Singleton

- reference implementation of Singleton design pattern in C++14
    - `unique_ptr` member variable for storing the instance
    - `make_unique` creation in `getInstance` function
- supports parametrized construction
- thread-safe
    - `static` member variable for storing the instance
    - synchronizing access to a resource Singleton holds via RAII mutex `lock_guard`

## Sources

-  Singleton (design pattern) as a Library Class/Static Class/Class (design pattern) - class with only static functions  
    https://github.com/kyberdrb/clean_pacman_cache_dir/commit/1e20a7130016c3ea0464613f2d53d20eae339d66
- ChatGPT OpenAI
    - What would a singleton design pattern look like n C++14 with unique_ptr?
    - In previous example, std::make_unique can't access the private constructor of the Singleton class. How would you solve this problem?
    - What would a singleton design pattern look like in C++14 with unique_ptr, make_unique function and deleted move and copy constructor and move and copy assignment operator and static member vairable?
    - In previous example. std::make_unique function can't access the private constructor of the Singleton class. How would you solve this issue?
- https://refactoring.guru/design-patterns/singleton
- https://refactoring.guru/design-patterns/singleton/cpp/example
- https://duckduckgo.com/?t=ffab&q=std%3Amake_unique+private+constructor+with+parameter&ia=web
- https://stackoverflow.com/questions/62249256/is-it-possible-to-use-stdmake-unique-in-a-class-constructor-and-this-pointer
- https://duckduckgo.com/?t=ffab&q=std%3A%3Alock_guard+unique_lock&ia=web
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+protect+thread+critical+section+lock_guard&ia=web
- https://www.apiref.com/cpp/cpp/thread/lock_guard.html