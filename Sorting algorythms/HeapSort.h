#pragma once
#include"BinaryHeap/BinaryHeap.h"
#include"BinaryHeap/DynamicArray.h"

using namespace std;

template <typename T>
void heapify(DynamicArray<T>& data, size_t n, size_t i) {
    size_t largest = i;      
    size_t left = 2 * i + 1;  
    size_t right = 2 * i + 2; 

    if (left < n && data[left] > data[largest]) {
        largest = left;
    }

    if (right < n && data[right] > data[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}

template <typename T>
DynamicArray<T> heapsort(const Heap<T>& heap) {
	DynamicArray<T> heapCopy = heap.getArray();

	size_t n = heap.getSize();

	for (int i = n / 2 - 1; i >= 0; --i) {
		(heapCopy, n, i);
	}

    for (int i = n - 1; i > 0; --i) {
        heapCopy.swap(0, i);
        heapify(heapCopy, i, 0)
    }
}
