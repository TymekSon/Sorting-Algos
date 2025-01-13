#include<iostream>
#include <string>
#include"CountingSort.h"
#include"BucketSort.h"
#include"BinaryHeap.h"

using namespace std;

template<typename T>
void print_array(const T* array, int n, int max_elements = 20) {
	for (int i = 0; i < min(n, max_elements); i++) {
		cout << array[i] << " ";
	}
	if (n > max_elements) cout << "...";
	cout << endl;
}

template<typename T>
void fill_array(T* array, int n) {
	for (int i = 0; i < n; i++) {
		array[i] = (rand() % 100);
	}
}

int main() {

	srand(0);
	const int MAX_ORDER = 7;
	const int m = static_cast<int>(pow(10, 7));
	char letters[] = "abcdefghijklmnopqrstuvwxyz";

	for (int o = 1; o <= MAX_ORDER; o++) {
		const int n = static_cast<int>(pow(10, o));

		cout << "Trial for " << n << "elements: \n\n";

		//Heapsort

		int* array1 = new int[n];
		fill_array(array1, n);
		cout << "\tBefore sorting: \t";
		print_array(array1, n);

		Heap<int> testHeap(array1, n, true);

		clock_t h1 = clock();
		DynamicArray<int> array1Sorted = testHeap.heapsort();
		clock_t h2 = clock();

		std::cout << "\tHeap sort, time: " << (double)(h2 - h1) / CLOCKS_PER_SEC << " s, first elements: ";
		cout << array1Sorted.str(20) << endl;
		cout << endl;

		//Counting Sort

		int* array2 = new int[n];
		fill_array(array2, n);
		cout << "\tBefore sorting: \t";
		print_array(array2, n);

		clock_t c1 = clock();
		int* array2Sorted = countingSort(array2, n);
		clock_t c2 = clock();

		std::cout << "\tCounting sort, time: " << (double)(c2 - c1) / CLOCKS_PER_SEC << " s, first elements: ";
		print_array(array2Sorted, n, 20);
		cout << endl;

		//Bucket Sort Int

		int* array3 = new int[n];
		fill_array(array3, n);
		cout << "\tBefore sorting: \t";
		print_array(array1, n);

		clock_t b1 = clock();
		int* array3Sorted = bucketSortInt(array2, n);
		clock_t b2 = clock();

		std::cout << "\tBucket sort int, time: " << (double)(b2 - b1) / CLOCKS_PER_SEC << " s, first elements: ";
		print_array(array3Sorted, n, 20);
		cout << endl;

		//Bucket Sort Type

		char* array4 = new char[n];
		for (int i = 0; i < n; i++) {
			array4[i] = letters[rand() % 26];
		}
		cout << "\tBefore sorting: \t";
		print_array(array4, n);
		clock_t t1 = clock();
		char* array4Sorted = bucketSortObj(array4, n);
		clock_t t2 = clock();

		std::cout << "\tBucket sort type, time: " << (double)(t2 - t1) / CLOCKS_PER_SEC << " s, first elements: ";
		print_array(array4Sorted, n, 20);
		cout << "\n\n";

		delete[] array1; array1Sorted.clear();
		delete[] array2; delete[] array2Sorted;
		delete[] array3; delete[] array3Sorted;
		delete[] array4; delete[] array4Sorted;
	}
	
}