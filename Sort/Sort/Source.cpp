#include <iostream>
#include <fstream>
#define SORTSTART
#include "sorters.h"

void randomarray(int*A, int len) {
	for (int i = 0; i < len; ++i) {
		A[i] = rand() % 9000 + 1000;
	}
}

//....................................................................................................................................
void sortedArray(int* A, int len) {
	for (int i = 0; i < len; ++i)
		A[i] = i;
}

//..........................................................................................................................................
void reversarray(int* A, int len) {
	for (int i = 0; i < len; ++i)
		A[i] = len - i;
}

//...................................................................................................................................
void Nearlyreversarray(int* A, int len) {
	for (int i = 0; i < len; ++i)
		A[i] = len - i;
	for (int i = 0; i < len / 2; ++i)
		std::swap(A[i], A[i + 1]);
}
//......................................................................................................................

void QuickSortKillerArray(int* A, int len) {
	for (int i = 0; i < len; ++i) A[i]=i;
	for (int i = 0; i < len; ++i) std::swap(A[i],A[i/2]);
}

//..................................................................................................................
template <typename T>
void print(T*A, int len, const char* str = "") {
	std::cout << str;
	for (int i = 0; i < len; ++i)
		std::cout << ' ' << A[i];
	std::cout << std::endl;
}
//..................................................................................
template <typename T>
bool isSorted(T*A, int len) {
	for (int i = 1; i < len; ++i)
		if (A[i] < A[i - 1]) return false;
	return true;
}
//..................................................................................................................

void SortArray(void(*sorter)(int*, int), int*A, int len, const char* arrayname) {
	std::cout << "---Array: " << arrayname << std::endl;
	if (len < 25) print(A, len, "before: ");
	sorter(A, len);
	if (!isSorted(A, len))
		std::cout << "Error: not sorted!" << std::endl;
	if (len<25) print(A, len, "After: ");
}
//......................................................................................................................

void Tester(void(*sorter)(int*, int), const int*R, int len, const char* name) {
	std::cout << "======================Method: " << name << "=========================" << std::endl;
	int *A = new int[len];
	sortedArray(A, len);
	SortArray(sorter, A, len, "Sorted");

	reversarray(A, len);
	SortArray(sorter, A, len, "Revered");

	Nearlyreversarray(A, len);
	SortArray(sorter, A, len, "Nearly Revered");

	QuickSortKillerArray(A, len);
	SortArray(sorter, A, len, "QuickSortKillerArray");

	for (int i = 0; i < len; ++i) A[i] = R[i];
	SortArray(sorter, A, len, "Random");

	delete[] A;
}
//...........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................


int main() {

	int n;
	do {
		std::cout << "Array size: ";
		std::cin >> n;
	} while (n <= 0);

	int* M = new int[n];
	randomarray(M, n);
	//print(M, n, "Random: ");

	//Tester(BubbleSort, M, n, "Bubble sorting ");
	//Tester(ChooseSort, M, n, "Choose sorting  ");
	//Tester(InsertSort, M, n, "Insert sorting  ");
	//Tester(InsertSortA, M, n, "Insert sorting (advanced)");
	Tester(QuickSortR, M, n, "QuickSortR sorting");//только до 4000, а то его убьёт
	//Tester(QuickSortS, M, n, "QuickSortS sorting"); не работает
	//Tester(MergeSort, M, n, "MergeSort sorting");
	//Tester(MergeSortA, M, n, "MergeSortA sorting");
	//Tester(HeapSort, M, n, "HeapSort sorting"); не работает

	delete[] M;
	system("pause");
	return 0;
}