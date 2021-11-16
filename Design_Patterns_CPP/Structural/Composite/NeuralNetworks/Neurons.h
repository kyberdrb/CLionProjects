#pragma once

class SingleNeuron;

template<typename Derived>
class Neurons {
public:
    template<typename T>
    void connectTo(T& neurons) {
        for(SingleNeuron& sourceNeuron : *(static_cast<Derived*>(this))) {
            for (SingleNeuron& destinationNeuron : neurons) {
                destinationNeuron.setCost();
                sourceNeuron.addNeuronToOutputStar(destinationNeuron);
                destinationNeuron.addNeuronToInputStar(sourceNeuron);
            }
        }
    }
};