#include <memory>
#include <cassert>

// Sharing with temporary ownership (std::weak_ptr): https://riptutorial.com/cplusplus/example/1673/sharing-with-temporary-ownership--std--weak-ptr-

int main() {
    {
        std::weak_ptr<int> wk;
        std::shared_ptr<int> sp;
        {
            std::shared_ptr<int> sh = std::make_shared<int>(42);
            wk = sh;
            sp = wk.lock(); // calling lock will create a shared_ptr to the object referenced by wk
            // sh will be destroyed after this point, but sp will be still alive
        }
        // sp still keeps the data alive.
        // At this point we could even call lock() again
        // to retrieve another shared_ptr to the same data from wk
        assert(*sp == 42);
        assert(!wk.expired());

        // resetting sp will delete the data,
        // as it is currently the last shared_ptr with ownership
        sp.reset();

        sp = wk.lock();
        assert(!sp);
        assert(wk.expired());
    }

    return 0;
}
