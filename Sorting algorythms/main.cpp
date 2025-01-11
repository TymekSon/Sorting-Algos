#include<iostream>
#include"HeapSort.h"
#include"BinaryHeap/BinaryHeap.h"
#include"BinaryHeap/DynamicArray.h"

using namespace std;

int main() {
	Heap<int> testHeap;

	for (int i = 0; i < 20; i++) {
		testHeap.insert(rand()%20);
	}

	testHeap.prettyPrint();

	DynamicArray<int> sorted = heapsort(testHeap);
	cout << sorted.str(20) << endl;
	return 0;
}