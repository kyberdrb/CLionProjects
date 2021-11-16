#include <iostream>
#include <memory>

// Sharing with temporary ownership (std::weak_ptr): https://riptutorial.com/cplusplus/example/1673/sharing-with-temporary-ownership--std--weak-ptr-

int main() {

    {
        std::weak_ptr<int> wp;
        std::cout << "wp: ref count:\t" << wp.use_count() << std::endl;
        {
            // std::make_shared is optimized by allocating only once
            // while std::shared_ptr<int>(new int(42)) allocates twice.
            // Drawback of std::make_shared is that control block is tied to our integer
            std::shared_ptr<int> sp = std::make_shared<int>(42);
            std::cout << "\tsp:\t" << *sp << std::endl;
            std::cout << "\tsp: ref count:\t" << sp.use_count() << std::endl;
            std::cout << "\twp: ref count:\t" << wp.use_count() << std::endl;
            wp = sp;
            std::cout << "\twp:\t" << *wp.lock() << std::endl;
            std::cout << "\tsp: ref count:\t" << sp.use_count() << std::endl;
            std::cout << "\twp: ref count:\t" << wp.use_count() << std::endl;
            // sp memory should be released at this point...
        }
        // ... but wk is still alive and needs access to control block from sp shared pointer
        std::cout << "wp: ref count:\t" << wp.use_count() << std::endl;
    }
    // now memory is released (sp and wk)

    return 0;
}
