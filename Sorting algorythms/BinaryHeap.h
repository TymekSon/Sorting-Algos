#pragma once

#include "DynamicArray.h"
#include <stdexcept>
#include <cmath> 
#include <iomanip>
#include <sstream>

using namespace std;

template <typename T>

class Heap {
private:
	DynamicArray<T> data;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data.get(parent) >= data.get(index)) {
                break;
            }
            data.swap(index, parent);
            index = parent;
        }
    }

    void heapifyDown(DynamicArray<T>& array, int index, size_t size) {
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && array.get(leftChild) > array.get(largest)) {
                largest = leftChild;
            }
            if (rightChild < size && array.get(rightChild) > array.get(largest)) {
                largest = rightChild;
            }
            if (largest == index) {
                break;
            }
            array.swap(index, largest);
            index = largest;
        }
    }

public:
    Heap() : data() {}

    Heap(T* array, int arraySize, bool useTopDown) : data() {
        for (int i = 0; i < arraySize; i++) {
            data.add(array[i]);
        }

        if (useTopDown) {
            for (int i = 1; i < data.getSize(); i++) {
                heapifyUp(i);
            }
        }
        else {
            for (int i = (data.getSize() / 2) - 1; i >= 0; i--) {
                heapifyDown(data, i, data.getSize());
            }
        }
    }

    void insert(T value) {
        data.add(value);
        heapifyUp(data.getSize() - 1);
    }

    T extractMax() {
        if (data.getSize() == 0) {
            throw out_of_range("Heap is empty");
        }
        T rootValue = data.get(0);
        data.set(0, data.get(data.getSize() - 1));
        data.remove(data.getSize() - 1);
        heapifyDown(data, 0, data.getSize());
        return rootValue;
    }

    T peekMax() const {
        if (data.getSize() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        return data.get(0);
    }

    void prettyPrint() {
        int size = data.getSize();
        int levels = lvl();
        cout << "Size: " << size << endl;
        cout << "Levels: " << levels << endl;

        int index = 0;
        int fieldWidth = 4;
        for (int i = 0; i < levels; i++) {
            for (int j = 0; j < pow(2, i) && index < size; j++) {
                if (j == 0) {
                    cout << setw(fieldWidth * pow(2, (levels - i)) / 2);
                }
                else {
                    cout << setw(fieldWidth * pow(2, (levels - i)));
                }

                auto value = data.get(index);
                if constexpr (std::is_pointer_v<decltype(value)>) {
                    cout << *value << ""; 
                }
                else {
                    cout << value << ""; 
                }
                index++;
            }
            cout << "\n";
        }
    }

    void shortPrint() {
        cout << "N. of elements: " << getSize() << endl;
        cout << "Heap levels:    " << lvl() << endl;
    }

    string str() const {
        ostringstream oss;

        int size = getSize();
        int levels = lvl();

        oss << "Size: " << size << "\n";
        oss << "Levels: " << levels << "\n";

        int index = 0;
        int fieldWidth = 4;

        for (int i = 0; i < levels; i++) {
            for (int j = 0; j < pow(2, i) && index < size; j++) {
                if (j == 0) {
                    oss << setw(fieldWidth * pow(2, (levels - i)) / 2) << data.get(index) << "  ";
                    index++;
                }
                else {
                    oss << setw(fieldWidth * pow(2, (levels - i)) - 2) << data.get(index) << "  ";
                    index++;
                }
            }
            oss << "\n";
        }

        return oss.str();
    }

    int getSize() const {
        return data.getSize();
    }

    int lvl() const {
        if (getSize() != 0) {
            return static_cast<int>(log2(getSize())) + 1;
        }
        return 0;
    }

    bool isEmpty() const {
        return data.getSize() == 0;
    }

    void clear() {
        data.clear();
    }

    DynamicArray<T> getArray() const{
        return data;
    }

    DynamicArray<T> heapsort() {
        DynamicArray<T> heapCopy = data;
        size_t size = data.getSize();

        for (int i = size / 2 - 1; i >= 0; --i) {
            heapifyDown(heapCopy, i, size);
        }

        for (int i = size - 1; i > 0; --i) {
            heapCopy.swap(0, i);
            heapifyDown(heapCopy, 0, i);
        }

        return heapCopy;
    }
};