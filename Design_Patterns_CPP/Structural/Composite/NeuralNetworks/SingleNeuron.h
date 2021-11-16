#pragma once

#include <vector>
#include <iostream>
#include <cstdint>

#include "NeuronIdPool.h"
#include "Neurons.h"

class SingleNeuron : public Neurons<SingleNeuron> {
private:
    unsigned int id;
    uint32_t cost;
    std::vector<SingleNeuron*> inputStar;
    std::vector<SingleNeuron*> outputStar;

public:
    SingleNeuron() {
        this->id = NeuronIdPool::getId();
        this->cost = 0;
    }

    SingleNeuron(uint32_t cost) {
        this->id = NeuronIdPool::getId();
        this->cost = cost;
    }

    friend std::ostream& operator<<(std::ostream& out, const SingleNeuron& neuron) {
        out << "Neuron: " << neuron.id << " - Input star" << "\n";
        for (SingleNeuron* inputNeuron : neuron.inputStar) {
            out << inputNeuron->id << " (" << inputNeuron->cost << ")" << "\t->\t" << "[" << neuron.id  << "]" << "\n";
        }

        out << "Neuron: " << neuron.id << " - Output star" << "\n";
        for (SingleNeuron* outputNeuron : neuron.outputStar) {
            out << "[" << neuron.id  << "]" << "\t->\t" << outputNeuron->id << " (" << outputNeuron->cost << ")"  << "\n";
        }

        return out;
    }

    SingleNeuron* begin() {
        return this;
    }

    SingleNeuron* end() {
        return this + 1;
    }

    void addNeuronToInputStar(SingleNeuron& neuron) {
        this->inputStar.emplace_back(&neuron);
    }

    void addNeuronToOutputStar(SingleNeuron& neuron) {
        this->outputStar.emplace_back(&neuron);
    }
};