#include <iostream>
#include <cstdint>
#include <memory>
#include <cassert>
#include <chrono>

class DynamicInterface {
public:
    virtual void tick(uint64_t n) = 0;
    virtual uint64_t getValue() = 0;
};

class DynamicImplementation : public DynamicInterface {
    uint64_t counter;

public:
    DynamicImplementation() : counter(0) {}

    void tick(uint64_t n) override {
        counter += n;
    }

    uint64_t getValue() override {
        return counter;
    }
};

const int N = 40000;

void run_dynamic(DynamicInterface* obj) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            obj->tick(j);
        }
    }
}

template <typename Implementation>
class CRTPInterface {
    Implementation& impl() {
        return static_cast<Implementation&>(*this);
    }

public:
    void tick(uint64_t n) {
        impl().tick(n);
    }

    uint64_t getValue() {
        return impl().getValue();
    }
};

class CRTPImplementation : public CRTPInterface<CRTPImplementation> {
    uint64_t counter;

public:
    CRTPImplementation() : counter(0) {}

    void tick(uint64_t n) {
        counter += n;
    }

    uint64_t getValue() {
        return counter;
    }
};

template <typename Implementation>
void run_crtp(CRTPInterface<Implementation>* obj) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            obj->tick(j);
        }
    }
}

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    auto dynamicImplementation = std::make_unique<DynamicImplementation>();
    run_dynamic(dynamicImplementation.get());

    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
            (end-start).count();

    std::cout << "dynamic polymorphism:\t" << elapsed_seconds << std::endl;

    start = std::chrono::system_clock::now();

    auto crtpImplementation = std::make_unique<CRTPInterface<CRTPImplementation>>();
    run_crtp(crtpImplementation.get());

    end = std::chrono::system_clock::now();
    elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
            (end-start).count();

    std::cout << "static polymorphism:\t" << elapsed_seconds << std::endl;

    assert(dynamicImplementation->getValue() == crtpImplementation->getValue());

    return 0;
}
