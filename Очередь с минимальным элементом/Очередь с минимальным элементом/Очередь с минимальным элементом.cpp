#include <iostream>
#include <fstream>

double* pop(double*& A, int& n) {
	double* B = new double[n + 10];
	for (int i = 0; i < n; ++i) {
		B[i] = A[i];
	}
	n += 10;
	delete[] A;
	return B;
}

void search_min(double*& A, int n, std::ofstream& out) {
	double min = A[0];
	for (int i = 1; i < n; ++i) {
		if (A[i] < min) {
			min = A[i];
		}
	}
	out << min;
	out << '\n';
}

int main()
{
	std::ifstream inFile;
	inFile.open("input.txt");
	if (!inFile) {
		std::cout << "Don't open file for writing";
		return 0;
	}
	int n, coll = 0;
	double tmp;
	char sym;
	inFile >> n;
	int range = n / 2;
	double* stek = new double[range];
	std::ofstream outFile;
	outFile.open("output.txt");
	if (!outFile) {
		std::cout << "Don't open file";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		inFile >> sym;
		switch (sym) {
		case '+': {
			inFile >> tmp;
			++coll;
			if (coll > range) {
				stek = pop(stek, range);
			}
			stek[coll - 1] = tmp;
			break;
		}
		case '-': {
			--coll;
			break;
		}
		case '?': {
			search_min(stek, coll, outFile);
			break;
		}
		}
	}

	outFile.close();
	inFile.close();
	delete[] stek;
	return 0;
}
