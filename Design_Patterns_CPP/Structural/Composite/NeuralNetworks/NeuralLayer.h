#pragma once

#include "Neurons.h"

class NeuralLayer : public Neurons<NeuralLayer> {
    std::vector<SingleNeuron> neurons;

public:
    explicit NeuralLayer(int numberOfNeurons) {
        for (int neuronIndex = 0; neuronIndex < numberOfNeurons; ++neuronIndex) {
            neurons.emplace_back(SingleNeuron{});
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const NeuralLayer& neuralLayer) {
        out << "Layer neurons" << "\n";
        for(const SingleNeuron& neuron : neuralLayer.neurons) {
            out << neuron << "\n";
        }
        return out;
    }

    std::vector<SingleNeuron>::iterator begin() {
        return neurons.begin();
    }

    std::vector<SingleNeuron>::iterator end() {
        return neurons.end();
    }
};