#include <iostream>
using namespace std;

int main() {
	int A = [10000];
	int n,x,k=0;
	cin << n;
	A[0] = 2;
	A[1] = 3;
	x = 1;
	for (int i = 5; i <10000; ++i) {
		int j = 0;
		for (int x = 2; x < A[i];x=A[++j])
			if (i % A[x] == 0) ++k;
		if (k == 0) A[++j] = i;
	}
	while (n > A[o]) { cout << A[o]<<"  "; ++o }


	return 0;
}