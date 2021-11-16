//
// Created by laptop on 7/23/19.
//

#ifndef CPP_11_NEW_FEATURES_RING_H
#define CPP_11_NEW_FEATURES_RING_H

#include <iostream>

template <typename T>
class ring {
private:
    T* m_values;
    int m_size;
    int m_position;

public:
    ring(int size)
    :
    m_position(0),
    m_size(size) {
        m_values = new T[size];
    }

    // Constructor with an initializer list allows for
    // initializing the data structure with fixed values
    // by using curly braces '{}',  e.g.
    //   ring<int> ringBuffer({2, 4, 6});
    ring(std::initializer_list<T> values)
    :
    ring(values.size()) {   // also using 'Constructor chaining' in order to reuse code and avoid duplication
        for (auto value: values) {
            add(value);
        }
    }
    void add(T value) {
        m_values[m_position] = value;
        m_position++;

        if (m_position == m_size) {
            m_position = 0;
        }
    }

    ~ring() {
        delete [] m_values;
    }

    int size() {
        return m_size;
    }

    T& get(int position) {
        return m_values[position];
    }

    T& operator[](int position) {
        return m_values[position];
    }

    class iterator;

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }
};

template <typename T>
class ring<T>::iterator {
private:
    int m_pos;
    ring& m_ring;

public:
    iterator(int pos, ring& ringBuf)
    :
    m_pos(pos), m_ring(ringBuf) {}

    iterator& operator++() {
        m_pos++;
        return *this;
    }

    iterator operator++(int) {
        iterator old = *this;
        operator++();
        return old;
    }

    T& operator*() {
        return m_ring[m_pos];
    }

    bool operator==(const iterator& otherIterator) {
        return m_pos == otherIterator.m_pos;
    }

    bool operator!=(const iterator& otherIterator) {
        return !(*this == otherIterator);
    }
};

#endif //CPP_11_NEW_FEATURES_RING_H
