//
// Created by laptop on 7/22/19.
//

#ifndef PASSINGFUNCTIONTOFUNCTION_LABRADOR_H
#define PASSINGFUNCTIONTOFUNCTION_LABRADOR_H


class Labrador : public Dog {
public:
    void run() override {
        std::cout << "Labrador running..." << std::endl << std::flush;
    }
};


#endif //PASSINGFUNCTIONTOFUNCTION_LABRADOR_H
