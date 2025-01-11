#include<iostream>
#include"HeapSort.h"
#include"CountingSort.h"
#include"BucketSort.h"
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

	//counting sort
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

	//bucket sort int
	int* testArray2 = new int[100]();

	for (int i = 0; i < 100; i++) {
		testArray2[i] = rand() % 100;
	}

	int* sortedArray2 = bucketSortInt(testArray2, 100);

	cout << "Before:\t\tAfter:" << endl;
	for (int i = 0; i < 100; i++) {
		cout << testArray2[i] << " \t\t";
		cout << sortedArray2[i] << "  " << endl;
	}

	delete[] sortedArray2;

	return 0;
}