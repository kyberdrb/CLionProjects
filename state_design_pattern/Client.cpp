#include "documentAsIfElseStateMachine/DocumentAsIfElseStateMachine.h"

#include "documentAsStateDesignPattern/Document.h"

#include <cassert>
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
    User user;
//    auto user = std::make_unique<User>(); // TODO rework user from stack allocated instance to an unique_ptr
    user.role = "user";
    Document document(user);

    std::cout
            << document.getCurrentUser()
            << " is publishing a document"
            << '\n';

    std::cout << "Initial state:\t" << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Next state:\t\t" << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Next state:\t\t" << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Next state:\t\t" << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Next state:\t\t" << document.getCurrentState() << '\n';

    // TOOO add more forward transitions
    // TODO add backwards transitions

}
