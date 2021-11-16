#include <iostream>
#include "Fighter.h"

void attack(Fighter& attacker, Fighter& opponent);
bool isFighterKilled(Fighter& fighter);
std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker);

int main() {
    Fighter fighter1("Lew", 10, 2);
    Fighter fighter2("Harry", 5, 4);

    std::string expected = "Lew";
    std::string actual = declareWinner(&fighter1, &fighter2, "Lew");
    std::cout << expected << " : " << actual << std::endl;

    fighter1 = Fighter{"Lew", 10, 2};
    fighter2 = Fighter{"Harry", 5, 4};

    expected = "Harry";
    actual = declareWinner(&fighter1, &fighter2, "Harry");
    std::cout << expected << " : " << actual << std::endl;
    return 0;
}

std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{
    Fighter* firstFighter = fighter1;
    Fighter* secondFighter = fighter2;

    if (firstAttacker == fighter2->getName()) {
        firstFighter = fighter2;
        secondFighter = fighter1;
    }

    std::string winnersName;

    while(true) {
        attack(*firstFighter, *secondFighter);

        if (isFighterKilled(*secondFighter)) {
            winnersName = firstFighter->getName();
            break;
        }

        attack(*secondFighter, *firstFighter);

        if (isFighterKilled(*firstFighter)) {
            winnersName = secondFighter->getName();
            break;
        }
    }

    return winnersName;
}

void attack(Fighter& attacker, Fighter& opponent) {
    opponent.setHealth(opponent.getHealth() - attacker.getDamagePerAttack());
}

bool isFighterKilled(Fighter& fighter) {
    return fighter.getHealth() <= 0;
}