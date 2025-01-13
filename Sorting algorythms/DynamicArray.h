#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

template <typename T>

class DynamicArray {
private:
    Node<T>* array;
    int size;
    int capacity;

    void expand(int expandedCapacity) {
        Node<T>* new_array = new Node<T>[expandedCapacity];
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        capacity = expandedCapacity;
    }
public:
    DynamicArray() : size(0), capacity(1) {
        array = new Node<T>[capacity];
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        array = new Node<T>[size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) return *this;
        delete[] array;
        array = other.array;
        size = other.size;
        other.array = nullptr;
        other.size = 0;
        return *this;
    }

    ~DynamicArray() {
        delete[] array;
    }

    Node<T>& operator[](size_t index) {
        return array[index]; 
    }

    const Node<T>& operator[](size_t index) const {
        return array[index];
    }

    void add(T value) {
        if (size >= capacity) {
            expand(static_cast<int>(capacity * 2.0));
        }
        array[size++].set(value);
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index].get();
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        array[index].set(value);
    }

    void swap(int index1, int index2) {
        if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T> temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        for (int i = index; i < size - 1; ++i) {
            array[i] = array[i + 1];
        }

        array[size - 1] = Node<T>();
        --size;
    }

    std::string str(int toDisplay = 10) const {
        std::ostringstream oss;
        oss << "Array(size=" << std::to_string(size) << ", capacity=" << std::to_string(capacity) << ")first elements: \n";
        int count = std::min(size, toDisplay);

        for (int i = 0; i < count; ++i) {
            oss << array[i].str() << " ";
        }
        return oss.str();
    }

    int getSize() const { return size; }

    int getCap() const { return capacity; }

    void clear() {
        delete[] array;
        size = 0;
        capacity = 1;
        array = new Node<T>[capacity];
    }
};