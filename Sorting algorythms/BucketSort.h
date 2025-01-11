#pragma once
#include<vector>
#include <algorithm>

using namespace std;

int Max(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int Min(int* array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int* bucketSortInt(int* array, int size) {
    int max = Max(array, size);
    int min = Min(array, size);

    int bucketCount = size;
    vector<float>* buckets = new vector<float>[bucketCount];

    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>(bucketCount * (array[i] - min) / (max - min + 1e-5)); 
        buckets[bucketIndex].push_back(array[i]);
    }

    int index = 0;
    int* copyArray = new int[size]();

    for (int i = 0; i < bucketCount; i++) {
        std::sort(buckets[i].begin(), buckets[i].end()); 
        for (float value : buckets[i]) {
            copyArray[index++] = value;
        }
    }

    delete[] buckets;
    return copyArray;
}

template<typename T>
T findMax(T* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

template<typename T>
T findMin(T* array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

template<typename T>
T* bucketSortObj(T* array, int size) {
    int min = findMin(array, size);
    int max = findMax(array, size);

    int bucketCount = size;
    vector<float>* buckets = new vector<float>[bucketCount];

    for (int i = 0; i < size; i++) {
        int bucketIndex = static_cast<int>(bucketCount * (array[i] - min) / (max - min + 1e-5));
        buckets[bucketIndex].push_back(array[i]);
    }

    int index = 0;
    T* copyArray = new T[size]();

    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        for (float value : buckets[i]) {
            copyArray[index++] = value;
        }
    }

    return copyArray;
}