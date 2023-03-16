#include "documentAsIfElseStateMachine/DocumentAsIfElseStateMachine.h"

#include "documentAsStateDesignPattern/Document.h"

#include <iostream>

void exampleOfPublishingDocumentAsIfElseStateMachine();
void exampleOfPublishingDocumentAsStateDesignPattern();

int main() {
    exampleOfPublishingDocumentAsIfElseStateMachine();

    std::cout << '\n' << "---" << "\n\n";

    exampleOfPublishingDocumentAsStateDesignPattern();
    return 0;
}

void exampleOfPublishingDocumentAsIfElseStateMachine() {
    ifElseStateMachine::User user;
    user.role = "user";
    ifElseStateMachine::DocumentAsIfElseStateMachine documentAsIfElseStateMachine(user);

    std::cout
        << documentAsIfElseStateMachine._currentUser
        << " has taken over the document"
        << '\n';

    std::cout << documentAsIfElseStateMachine.state << '\n';

    documentAsIfElseStateMachine.publish();
    std::cout << documentAsIfElseStateMachine.state << '\n';

    documentAsIfElseStateMachine.publish();
    std::cout << documentAsIfElseStateMachine.state << '\n';

    ifElseStateMachine::User publisher;
    publisher.role = "admin";

    documentAsIfElseStateMachine.switchCurrentUser(publisher);

    std::cout
            << documentAsIfElseStateMachine._currentUser
            << " is publishing a document"
            << '\n';

    documentAsIfElseStateMachine.publish();
    std::cout << documentAsIfElseStateMachine.state << '\n';

    documentAsIfElseStateMachine.publish();
    std::cout << documentAsIfElseStateMachine.state << '\n';
}

void exampleOfPublishingDocumentAsStateDesignPattern() {
    auto user = std::make_unique<User>(); // TODO rework user from stack allocated instance to an unique_ptr
    user->role = "user";
    Document document(*user);

    std::cout
            << document.getCurrentUser()
            << " is publishing a document"
            << '\n';

    std::cout << "Initial state:\t\t\t" << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << document.getCurrentState() << '\n';

    document.returnDocAfterReview();
    std::cout << "Transition type: returnDocAfterReview" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tpublished -> " << document.getCurrentState() << '\n';

    document.expire();
    std::cout << "Transition type: expire" << '\n';
    std::cout << "State change:\t\t\tpublished -> " << document.getCurrentState() << '\n';

    // TODO test state machine for an User in 'admin' role
    // TODO make 'ADMIN' and 'USER' an enum class that will the User class accept
    //  - as a constructor parameter?
    //  - as a 'promoteToAdmin' function?

    // TODO remember previous state on 'changeState'?
    // TODO make State virtual functions return a Transition object/instance for the client to print it out to terminal
}
