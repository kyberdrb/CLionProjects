#include <iostream>
#include <array>
#include <map>

//class Creature {
//private:
//    int strength, agility, intelligence;
//
//public:
//    int getStrength() const {
//        return strength;
//    }
//
//    void setStrength(int strength) {
//        Creature::strength = strength;
//    }
//
//    int getAgility() const {
//        return agility;
//    }
//
//    void setAgility(int agility) {
//        this->agility = agility;
//    }
//
//    int getIntelligence() const {
//        return intelligence;
//    }
//
//    void setIntelligence(int intelligence) {
//        Creature::intelligence = intelligence;
//    }
//};

//class Creature {
//private:
//    enum Abilities {str, agl, count};    // count hack for C-style enum: the last element has the index that corresponds to the number of elements in enum
//    std::array<int, count> abilities;
//    std::map<Abilities, int> capabilities;
//
//public:
//    int getStrength() const {
//        //return abilities[str];
//        capabilities.insert(std::make_pair(Abilities::))
//    }
//
//    void setStrength(int strength) {
//        abilities[str] = strength;
//    }
//
//    int getAgility() const {
//        return abilities[agl];
//    }
//
//    void setAgility(int agility) {
//        abilities[agl] = agility;
//    }
//};

class Creature {
private:
    enum class Abilities {str, agl, count};
    std::map<Abilities, int> capabilities;

public:
    int getStrength() const {
        auto pair = capabilities.find(Abilities::str);
        return pair->second;
    }

    void setStrength(int strength) {
        capabilities.emplace(std::make_pair(Abilities::str, strength));
    }

    int getAgility() const {
        auto pair = capabilities.find(Abilities::agl);
        return pair->second;
    }

    void setAgility(int agility) {
        capabilities.insert(std::make_pair(Abilities::agl, agility));
    }
};

int main() {
    Creature orc;
    orc.setStrength(100);
    orc.setStrength(100);
    orc.setAgility(10);
    std::cout << orc.getStrength() << "," << orc.getAgility() << std::endl;
    return 0;
}