#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Merge(int* M, int first, int middle, int last);

void Split(int* M, int first, int last, vector <int>& begin, vector <int>& end, vector <int>& firstInd, vector <int>& lastInd) {
	if (first == last) {
		begin.push_back(first + 1);
		end.push_back(first + 1);
		firstInd.push_back(M[first]);
		lastInd.push_back(M[first]);
	}
	if (first < last) {
		int middle = first + (last - first) / 2;
		Split(M, first, middle, begin, end, firstInd, lastInd);
		Split(M, middle + 1, last, begin, end, firstInd, lastInd);
		begin.push_back(first + 1);
		end.push_back(last + 1);
		firstInd.push_back(M[first]);
		lastInd.push_back(M[last]);
		Merge(M, first, middle, last);
	}
}

void Merge(int* M, int first, int middle, int last) {
	int* tmp = new int[last - first + 1];
	int start1 = first, end1 = middle, start2 = middle + 1, end2 = last;
	int ind = 0;
	while (start1 <= end1 && start2 <= end2) {
		if (M[start1] < M[start2]) {
			tmp[ind++] = M[start1++];
		}
		else {
			tmp[ind++] = M[start2++];
		}
	}
	while (start1 <= end1) tmp[ind++] = M[start1++];
	while (start2 <= end2) tmp[ind++] = M[start2++];
	ind = 0; while (first <= last) M[first++] = tmp[ind++];
	delete[] tmp;
}


int main() {
	ifstream inFile("input.txt");
	if (!inFile) {
		cout << "Can not open input file";
	}
	ofstream outFile("output.txt");
	if (!outFile) {
		cout << "Can not open output file";
	}
	int n;
	inFile >> n;
	int* A = new int[n];
	vector <int> begin;
	vector <int> end;
	vector <int> firstInd;
	vector <int> lastInd;
	for (int i = 0; i < n; ++i) {
		inFile >> A[i];
	}
	Split(A, 0, n - 1, begin, end, firstInd, lastInd);
	for (int i = 0; i < begin.size(); ++i) {
		outFile << begin[i] << ' ' << end[i] << ' ' << firstInd[i] << ' ' << lastInd[i] << endl;
	}
	for (int i = 0; i < n; ++i) {
		outFile << A[i] << ' ';
	}
	inFile.close();
	outFile.close();
	return 0;
}