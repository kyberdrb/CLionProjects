#include <memory>
#include <cassert>
#include <iostream>

// C++ Core Guidelines: Rules for Smart Pointers:
// - R.30: Take smart pointers as parameters only to explicitly express lifetime semantics: https://www.modernescpp.com/index.php/c-core-guidelines-rules-to-smart-pointers

void modifyOneSharedResource_changeItForAllOthers(int& sharedResource);
void whenYouChangeLifetimeOfSharedPtrPassA_SmartPtr(std::shared_ptr<int>& sharedResource);
void whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr(std::shared_ptr<int> sharedResource);
//void whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr(const std::shared_ptr<int>& sharedResource);
void whenYouDontChangeLifetimeOfSharedPtrPassA_ReferenceToUnderlyingResource(int& sharedUnderlyingResource);

int main() {
    auto firstSharedResource = std::make_shared<int>(12);
    auto secondSharedResource = firstSharedResource;
    assert(firstSharedResource.use_count() == 2);
    std::cout << "2 owners of the instance firstSharedResource:\n"
                 "\tfirstSharedResource and secondSharedResource" << std::endl;

    std::cout << std::endl;
    assert(*firstSharedResource == 12);
    assert(*secondSharedResource == 12);
    std::cout << *firstSharedResource << std::endl;
    std::cout << *secondSharedResource << std::endl;
    std::cout << std::endl;

    modifyOneSharedResource_changeItForAllOthers(*firstSharedResource);
    assert(*firstSharedResource == 23);
    assert(*secondSharedResource == 23);
    std::cout << "change value of the shared resource:\n"
                 "\tthe change of a shared resource affect all owners of that resource:\n"
                 "\tint our case the firstSharedResource and secondSharedResource" << std::endl;
    std::cout << *firstSharedResource << std::endl;
    std::cout << *secondSharedResource << std::endl;
    std::cout << std::endl;

    whenYouChangeLifetimeOfSharedPtrPassA_SmartPtr(firstSharedResource);
    assert(firstSharedResource.use_count() == 1);
    std::cout << "passing a shared_ptr by value:\n"
             "\townership of the firstSharedResource is still maintained:\n"
             "\t2 owners: firstSharedResource and secondSharedResource" << std::endl;
//    assert(firstSharedResource.use_count() == 2);
//    std::cout << "passing a shared_ptr by value:\n"
//                 "\townership of the firstSharedResource is still maintained:\n"
//                 "\t2 owners: firstSharedResource and secondSharedResource" << std::endl;

    std::cout << std::endl;
    assert(*firstSharedResource == 34);
    assert(*secondSharedResource == 23);
    std::cout << *firstSharedResource << std::endl;
    std::cout << *secondSharedResource << std::endl;
    std::cout << std::endl;

    whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr(secondSharedResource);   // error: call of overloaded ‘whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr(std::shared_ptr<int>&)’ is ambiguous
                                                                                    // candidate: void whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr(std::shared_ptr<int> sharedResource);
                                                                                    // candidate: void whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr(const std::shared_ptr<int>& sharedResource);
    assert(secondSharedResource.use_count() == 1);

    std::cout << std::endl;
    assert(*firstSharedResource == 34);
    assert(*secondSharedResource == 56);
    std::cout << *firstSharedResource << std::endl;
    std::cout << *secondSharedResource << std::endl;
    std::cout << std::endl;

    whenYouDontChangeLifetimeOfSharedPtrPassA_ReferenceToUnderlyingResource(*secondSharedResource);
    assert(secondSharedResource.use_count() == 1);

    std::cout << std::endl;
    assert(*firstSharedResource == 34);
    assert(*secondSharedResource == 89);
    std::cout << *firstSharedResource << std::endl;
    std::cout << *secondSharedResource << std::endl;
    std::cout << std::endl;

    return 0;
}

void modifyOneSharedResource_changeItForAllOthers(int& sharedResource) {
    sharedResource += 11;
}

void whenYouChangeLifetimeOfSharedPtrPassA_SmartPtr(std::shared_ptr<int>& sharedResource) {
    assert(sharedResource.use_count() == 2);    // passing shared_ptr by reference maintains the ref count, i.e. the ref count doesn't change
//    assert(sharedResource.use_count() == 3);    // passing shared_ptr by value increases the ref count; the parameter
                                                // of the function, 'sharedResource', also becomes an owner of the resource
    std::cout << "whenYouChangeLifetimeOfSharedPtrPassA_SmartPtr:\n"
                 "\t3 owners: firstSharedResource in main(), secondSharedResource in main() and sharedResource in this function as a parameter with a value copied from main()" << std::endl;

    sharedResource.reset(new int(34));
    assert(sharedResource.use_count() == 1);

    std::cout << "whenYouChangeLifetimeOfSharedPtrPassA_SmartPtr:\n"
                 "\tlocal ownership changed after resetting the resource to another one in 'sharedResource' parameter.\n"
                 "\tnow the only owner is sharedResource variable passed as a parameter to this function" << std::endl;
}

void whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr(std::shared_ptr<int> sharedResource) {
    assert(sharedResource.use_count() == 2);
//    assert(sharedResource.use_count() == 3);
    std::cout << "whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr:\n"
                 "\tthe number of owners is at the beginning the same as in whenYouChangeLifetimeOfSharedPtrPassA_SmartPtr" << std::endl;

    *sharedResource += 33;
    assert(sharedResource.use_count() == 2);
//    assert(sharedResource.use_count() == 3);

    std::cout << "whenYouDontChangeLifetimeOfSharedPtrDontPassA_SmartPtr:\n"
                 "\tthe number of owners is at the end the same as at the beginning of this function\n"
                 "\twe didn't modify the lifetime of the passed shared_ptr" << std::endl;
}

void whenYouDontChangeLifetimeOfSharedPtrPassA_ReferenceToUnderlyingResource(int& sharedUnderlyingResource) {
    std::cout << "whenYouDontChangeLifetimeOfSharedPtrPassA_ReferenceToUnderlyingResource:\n"
                 "\tthe number of owners is the same at the end and at the beginning of this function\n"
                 "\tbecause we don't modify the lifetime of the shared_ptr;\n"
                 "\twe only modify the underlying resource from the shared_ptr from main()" << std::endl;
    sharedUnderlyingResource += 33;
}
