#include "SingleNeuron.h"
#include "NeuralLayer.h"

int main() {
    SingleNeuron n0(100), n1(101);

    std::cout << n0 << std::endl;
    std::cout << n1 << std::endl;

    n0.connectTo(n1);

    std::cout << n0 << std::endl;
    std::cout << n1 << std::endl;

    NeuralLayer layer1(2);
    NeuralLayer layer2{3};

    std::cout << layer1 << std::endl;

    std::cout << "===" << std::endl << std::endl;

    n0.connectTo(layer1);
    layer2.connectTo(n1);
    layer1.connectTo(layer2);
    std::cout << n0 << std::endl;

    std::cout << std::endl;

    std::cout << layer1 << std::endl;
}