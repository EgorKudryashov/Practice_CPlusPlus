#include <iostream>
#include <time.h>
int main() {
    int n , m ;
	std::cout << "Input n= ";
    std::cin>> n;
	std::cout << "Input m= ";
	std::cin >> m;
	int k = 1;
	int M[10][10];
	int N[10][10];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			M[i][j] = rand();
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			std::cout << M[i][j] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;

	int i1 , j1 = -1;
	for (int i = 0; i < m; ++i) {
		++j1;
		i1 = -1;
		for (int j = 0; j <n; ++j) {
			++i1;
			N[i][j] = M[i1][j1];
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = n-1; j>=0; --j)
			std::cout << N[i][j] << '\t';
		std::cout << std::endl;

	}
		return 0;
	
}