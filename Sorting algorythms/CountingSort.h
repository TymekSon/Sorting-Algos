#pragma once

int findMax(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int findMin(int* array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int* countingSort(int* array, int size) {
    int min = findMin(array, size);
    int max = findMax(array, size);

    int* arrayCount = new int[max - min + 1](); 

    for (int i = 0; i < size; i++) {
        arrayCount[array[i] - min]++;
    }

    int* arrayCopy = new int[size];
    int index = 0;

    for (int i = 0; i <= max - min; i++) {
        while (arrayCount[i] > 0) {
            arrayCopy[index++] = i + min;
            arrayCount[i]--;
        }
    }

    delete[] arrayCount;

    return arrayCopy;
}
