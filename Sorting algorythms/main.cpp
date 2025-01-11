#include<iostream>
#include"HeapSort.h"
#include"CountingSort.h"
#include"BinaryHeap/BinaryHeap.h"
#include"BinaryHeap/DynamicArray.h"

using namespace std;

int main() {
	// heapsort
	Heap<int> testHeap;

	for (int i = 0; i < 20; i++) {
		testHeap.insert(rand()%100);
	}

	testHeap.prettyPrint();

	DynamicArray<int> sorted = heapsort(testHeap);
	cout << sorted.str(20) << endl;

	//countin sort
	int* testArray = new int[100]();

	for (int i = 0; i < 100; i++) {
		testArray[i] = rand() % 100;
	}

	int* sortedArray = countingSort(testArray, 100);

	cout << "Before:\t\tAfter:" << endl;
	for (int i = 0; i < 100; i++) {
		cout << testArray[i] << " \t\t";
		cout << sortedArray[i] << "  " << endl;
	}

	delete[] sortedArray;

	return 0;
}