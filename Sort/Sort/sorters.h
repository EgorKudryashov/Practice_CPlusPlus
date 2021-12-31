#ifndef _MYSORTS2019_

#define _MYSORTS2019_
#include <time.h>
#include <utility>

template <typename T>
void BubbleSort(T* A, int n) {
#ifdef SORTSTART
	unsigned long long c1 = 0, c2 = 0;
	clock_t t = clock();
#endif SORTSTARS
	bool isSorted;
	for (int j = 0; j < n-1; ++j) {
		isSorted = true;
		for (int i = n - 1; i > j; --i) {
#ifdef SORTSTART
			++c1;
#endif SORTSTARS
			if (A[i] < A[i - 1]) {
				std::swap(A[i], A[i-1]);
#ifdef SORTSTART
				c2 += 3;
#endif SORTSTARS
				isSorted = false;
			}
			
		}
		if (isSorted) break;
	}
#ifdef SORTSTART
	t = clock() - t;
	std::cout << "<" << c1 << ", = " << c2 << ", tics: " << t << std::endl;
#endif SORTSTARS
}
//....................................................................

template <typename T>
void ChooseSort(T*A, int n) {
#ifdef SORTSTART
	unsigned long long c1 = 0, c2 = 0;
	clock_t t = clock();
#endif SORTSTARS
	for (int j = 0; j < n - 1; ++j) {
		int k = j;
		for (int i = j + 1; i < n; ++i) {
#ifdef SORTSTART
			++c1;
#endif SORTSTARS
			if (A[i] < A[k]) k = i;
		}
		if (k > j) {
			std::swap(A[k], A[j]);
#ifdef SORTSTART
			c2 +=3;
#endif SORTSTARS
		}
	}
#ifdef SORTSTART
	t = clock() - t;
	std::cout << "<" << c1 << ", = " << c2 << ", tics: " << t << std::endl;
#endif SORTSTARS
}
//.....................................................................

template<typename T>
void InsertSort(T*A, int n){
	T tmp;
#ifdef SORTSTART
	unsigned long long c1 = 0, c2 = 0;
	clock_t t = clock();
#endif SORTSTARS
	for (int j = 1; j < n; ++j) {
		tmp = A[j];
#ifdef SORTSTART
		++c2;
#endif SORTSTARS
		int i;
		for ( i = j; i > 0; --i) {
#ifdef SORTSTART
			++c1;
#endif SORTSTARS
			if (tmp < A[i - 1]) {
				A[i] = A[i - 1];
#ifdef SORTSTART
				++c2;
#endif SORTSTARS
			}
			else
				break;
		}
		if (i != j) {
			A[i] = tmp;
#ifdef SORTSTART
			++c2;
#endif SORTSTARS
		}
	}

#ifdef SORTSTART
	t = clock() - t;
	std::cout << "<" << c1 << ", = " << c2 << ", tics: " << t << std::endl;
#endif SORTSTARS
}
//.....................................................................

template <typename T>
void InsertSortA(T*A, int n) {
#ifdef SORTSTART
	unsigned long long c1 = 0, c2 = 0;
	clock_t t = clock();
#endif SORTSTARS
	for (int j = 1; j < n; ++j) {
		T tmp;
		int left = 0, right = j, mid;
		do {
			mid = left + (right - left) / 2;
#ifdef SORTSTART
			++c1;
#endif SORTSTARS
			if (A[j] < A[mid])
				right = mid - 1;
			else
				left = mid + 1;
		} while (left < right);
#ifdef SORTSTART
		++c1;
#endif SORTSTARS
		if (right >= 0) {
			if (A[j] < A[right]) --right;
		}
#ifdef SORTSTART
		++c1;
#endif SORTSTARS
		if (j > right + 1) {
			tmp = A[j];
			for (int i = j; i > right + 1; --i) {
				A[i] = A[i - 1];
#ifdef SORTSTART
				++c2;
#endif SORTSTARS
			}
			A[right + 1] = tmp;
		}
	}
#ifdef SORTSTART
	t = clock() - t;
	std::cout << "<" << c1 << ", = " << c2 << ", tics: " << t << std::endl;
#endif SORTSTARS
}
//......................................................................

template <typename T>
void QuickSortR(T*A, int n) {
	int left = 0, right = n - 1;
	int pindex = left + (right - left) / 2;
	T p = A[pindex];
	int i = left, j = right;
	while (i < j) {
		while (A[i] < p) { ++i; }
		while (A[j] > p) { --j; }
		if (i < j) {
			std::swap(A[i], A[j]);
			++i; --j;
		}
		else if (i == j) {
			++i; --j;
		}
	}
	if (pindex < i) {//правая часть меньше чем левая
		if (i < right) QuickSortR(A + i, right - i + 1);
		if (j > left) QuickSortR(A + left, j - left + 1);
	}
	else {
		if (j > left) QuickSortR(A + left, j - left + 1);
		if (i < right) QuickSortR(A + i, right - i + 1);
	}
}
//....................................................................

template <typename T>
void QuickSortS(T*A, int n) {
	int N = n, size = 1;
	while (N > 0) {
		N >>= 1; 
		++size;
	}
#ifdef SORTSTART
	unsigned long long c1 = 0, c2 = 0;
	clock_t t = clock();
#endif 
	int *StackLeft = new int[size];
	int *StackRight = new int[size];
	int LastInStack = -1;
	++LastInStack;
	StackLeft[LastInStack] = 0;
	StackRight[LastInStack] = n-1;
	while (LastInStack > -1) {
		int left = StackLeft[LastInStack];
		int right = StackRight[LastInStack];
		--LastInStack;
		int pindex = left + (right - left) / 2;
		T p = A[pindex];
#ifdef SORTSTART
		++c2;
#endif 
		int i = left, j = right;
#ifdef SORTSTART
		c1 += right-left+1;
#endif 
		while (i < j) {
			while (A[i] < p) { ++i; }
			while (p < A[i]) { --j; }
			if (i < j) {
				std::swap(A[i], A[j]);
				++i; --j;
#ifdef SORTSTART
				c2 += 3;
#endif 
			}else if (i == j) { ++i; --j; }
		}
		if (i > pindex) {
			if (j > left) {
				++LastInStack;
				StackLeft[LastInStack] = left;
				StackRight[LastInStack] = j;
			}
			if (i < right) {
				++LastInStack;
				StackLeft[LastInStack] = i;
				StackRight[LastInStack] = right;
			}
		}
		else {
			if (i < right) {
				++LastInStack;
				StackLeft[LastInStack] = i;
				StackRight[LastInStack] = right;
			}
			if (j > left) {
				++LastInStack;
				StackLeft[LastInStack] = left;
				StackRight[LastInStack] = j;
			}
		}
	}
	delete[] StackLeft;
	delete[] StackRight;
#ifdef SORTSTART
	t = clock() - t;
	std::cout << "<" << c1 << ", = " << c2 << ", tics: " << t << std::endl;
#endif 
}
//..................................................................................


template <typename T>
void _Split(T* A, int first, int last, unsigned long long &c1, unsigned long long &c2) {
	if (first < last) {
		int middle = first + (last - first) / 2;
		_Split(A, first, middle, c1, c2);
		_Split(A, middle+1, last, c1, c2);
		_Merge(A, first, middle, last, c1, c2);
	}

}

template <typename T>
void _Merge(T* A, int first,int middle, int last, unsigned long long &c1, unsigned long long &c2) {
	int size = last - first + 1;
	T* tmp = new int[size];
	int start1 = first, end1 = middle, start2 = middle + 1, end2 = last;
	int i = 0;
	while (start1 <= end1 && start2 <= end2) {
		if (A[start1] < A[start2]) {
			tmp[i++] = A[start1++];
		}
		else {
			tmp[i++] = A[start2++];
		}
		++c1;
		++c2;
	}
	while (start1 <= end1) { tmp[i++] = A[start1++]; ++c2; }
	while (start2 <= end2) { tmp[i++] = A[start2++]; ++c2; }
	//Копируем обратно из tmp в A
	i = 0;
	while (first <= last) { A[first++] = tmp[i++]; ++c2; }
	delete[] tmp;
}

template <typename T>
void MergeSort(T* A, int n) {
	unsigned long long c1 = 0, c2 = 0;
	clock_t t = clock();

	_Split(A, 0, n - 1,c1,c2);

#ifdef SORTSTART
	t = clock() - t;
	std::cout << "<" << c1 << ", = " << c2 << ", tics: " << t << std::endl;
#endif 
}
//.........................................................................................

template <typename T>
void MergeSortA(T*A, int n) {
	T* tmp = new T[n];
	T* from = A, *to = tmp;
	unsigned long long c1 = 0, c2 = 0;
	clock_t t = clock();
	for (int step = 1; step < n; step *= 2) {
		int start1 = 0, end1, start2, end2;
		int i = 0;//Индекс в массиве tmp
		for (int start = 0; start < n; start += 2 * step) {
			start1 = start; end1 = start1 + step; end1 = (end1 < n) ? end1 : n;
			start2 = end1; end2 = start2 + step; end2 = (end2 < n) ? end2 : n;
			while (start1 < end1 && start2 < end2) {
				to[i++] = (from[start1] < from[start2]) ? from[start1++] : from[start2++];
				++c1;
			}
			while (start1 < end1) { to[i++] = from[start1++];  }
			while (start2 < end2) { to[i++] = from[start2++];  }
		}
		c2 += n;
		std::swap(from, to);

	}

	if (from != A) {
		//копируем из отсортированного массива в A
		int i = 0;
		while (i < n) { A[i] = from[i++]; }
		c2 += n;
	}
	delete[] tmp;
#ifdef SORTSTART
	t = clock() - t;
	std::cout << "<" << c1 << ", = " << c2 << ", tics: " << t << std::endl;
#endif 
}
//..............................................................................................

template<typename T>
void HeapSort(T*A, int n) {
#ifdef SORTSTART
	unsigned long long c1 = 0, c2 = 0;
	clock_t t = clock();
#endif 
	//make heap
	for (int i = 1; i < n; ++i) {
		int pos = i;
		while (pos != 0) {
#ifdef SORTSTART
			++c1;
#endif 
			if (A[(pos - 1) / 2] < A[pos]) {
				std::swap(A[pos], A[(pos - 1) / 2]);
				pos = (pos - 1) / 2;
			}
			else break;
		}
	}
	//shift down each element
	int size = n;
	for (int i = 1; i < n; ++i) {
		std::swap(A[0], A[size - 1]);
#ifdef SORTSTART
		c2 += 3;
#endif 
		--size;
		int pos = 0;
		while (2 * pos + 1 < size) {
			int posMaxChild = 2 * pos + 1;
			if (2 * pos + 2 < size) {
#ifdef SORTSTART
				++c1;
#endif 
				if (A[posMaxChild] < A[posMaxChild + 1])
					++posMaxChild;
			}
#ifdef SORTSTART
			++c1;
#endif 
			if (A[pos] < A[posMaxChild]) {
				std::swap(A[pos], A[posMaxChild]);
#ifdef SORTSTART
				c2 += 3;
#endif 
				pos = posMaxChild;
			}
			else break;
		}
	}
#ifdef SORTSTART
	t = clock() - t;
	std::cout << "<" << c1 << ", = " << c2 << ", tics: " << t << std::endl;
#endif 
}
//...................................................................................

#endif