#pragma once

class NeuronIdPool {
    static unsigned int id;

public:
    static int getId() {
        return id++;
    }
};

unsigned int NeuronIdPool::id = 0;