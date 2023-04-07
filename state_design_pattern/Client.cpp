#include "documentAsIfElseStateMachine/DocumentAsIfElseStateMachine.h"

#include "documentAsStateDesignPattern/Document.h"

#include "documentAsStateDesignPatternProduction/Document.h"
#include "documentAsStateDesignPatternProduction/UserRole.h"

#include <iostream>

void exampleOfPublishingDocumentAsIfElseStateMachine();
void exampleOfPublishingDocumentAsStateDesignPattern();
void exampleOfPublishingDocumentAsStateDesignPatternProduction();

int main() {
    exampleOfPublishingDocumentAsIfElseStateMachine();

    std::cout << '\n' << "---" << "\n\n";

    exampleOfPublishingDocumentAsStateDesignPattern();

    std::cout << '\n' << "---" << "\n\n";

    exampleOfPublishingDocumentAsStateDesignPatternProduction();

    return 0;
}

void exampleOfPublishingDocumentAsIfElseStateMachine() {
    ifElseStateMachine::User user;
    user.role = "user";
    ifElseStateMachine::DocumentAsIfElseStateMachine documentAsIfElseStateMachine(user);

    std::cout
            << documentAsIfElseStateMachine._currentUser
            << " is publishing a document"
            << '\n';

    std::cout << "Initial state:\t\t\t" << documentAsIfElseStateMachine.state << '\n';

    documentAsIfElseStateMachine.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << documentAsIfElseStateMachine.state << '\n';

    documentAsIfElseStateMachine.returnedFromReview = true;
    documentAsIfElseStateMachine.publish();
    std::cout << "Transition type: returnDocAfterReview" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << documentAsIfElseStateMachine.state << '\n';
    documentAsIfElseStateMachine.resetSpecialAttributes();

    documentAsIfElseStateMachine.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << documentAsIfElseStateMachine.state << '\n';

    documentAsIfElseStateMachine.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << documentAsIfElseStateMachine.state << '\n';

    std::cout << "...\n";

    documentAsIfElseStateMachine._currentUser.role = "admin";
    documentAsIfElseStateMachine.resetSpecialAttributes();

    std::cout
            << documentAsIfElseStateMachine._currentUser
            << " is publishing a document"
            << '\n';

    documentAsIfElseStateMachine.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << documentAsIfElseStateMachine.state << '\n';

    documentAsIfElseStateMachine.expired = true;
    documentAsIfElseStateMachine.publish();
    std::cout << "Transition type: expire" << '\n';
    std::cout << "State change:\t\t\tpublished -> " << documentAsIfElseStateMachine.state << '\n';
    documentAsIfElseStateMachine.resetSpecialAttributes();

    documentAsIfElseStateMachine.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << documentAsIfElseStateMachine.state << '\n';

    documentAsIfElseStateMachine.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tpublished -> " << documentAsIfElseStateMachine.state << '\n';
}

void exampleOfPublishingDocumentAsStateDesignPattern() {
    auto user = std::make_unique<User>();
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

    std::cout << "...\n";

    user->role = "admin";

    std::cout
            << document.getCurrentUser()
            << " is publishing a document"
            << '\n';

    document.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << document.getCurrentState() << '\n';

    document.expire();
    std::cout << "Transition type: expire" << '\n';
    std::cout << "State change:\t\t\tpublished -> " << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << document.getCurrentState() << '\n';

    document.publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tpublished -> " << document.getCurrentState() << '\n';
}

void exampleOfPublishingDocumentAsStateDesignPatternProduction() {
    auto user = std::make_unique<production::User>(production::UserRole::USER);
    auto document = std::make_unique<production::Document>(*user);

    std::cout
            << document->getCurrentUser()
            << " is publishing a document"
            << '\n';

    std::cout << "Initial state:\t\t\t" << document->getCurrentState() << '\n';

    document->publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << document->getCurrentState() << '\n';

    document->returnDocAfterReview();
    std::cout << "Transition type: returnDocAfterReview" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << document->getCurrentState() << '\n';

    document->publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << document->getCurrentState() << '\n';

    document->publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << document->getCurrentState() << '\n';

    std::cout << "...\n";

    auto admin = std::make_unique<production::User>(production::UserRole::ADMIN);
    document->changeUser(*admin);

    std::cout
            << document->getCurrentUser()
            << " is publishing a document"
            << '\n';

    document->publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tmoderation -> " << document->getCurrentState() << '\n';

    document->expire();
    std::cout << "Transition type: expire" << '\n';
    std::cout << "State change:\t\t\tpublished -> " << document->getCurrentState() << '\n';

    document->publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tdraft -> " << document->getCurrentState() << '\n';

    document->publish();
    std::cout << "Transition type: publish" << '\n';
    std::cout << "State change:\t\t\tpublished -> " << document->getCurrentState() << '\n';
}
