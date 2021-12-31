#include <iostream>
#include <time.h>
int main() {
	int n1, m1;
	std::cout << "Input n1= ";
	std::cin >> n1;
	std::cout << "Input m1= ";
	std::cin >> m1;
	int n2, m2;
	std::cout << "Input n2= ";
	std::cin >> n2;
	std::cout << "Input m2= ";
	std::cin >> m2;

	int M[10][10];
	int N[10][10];
	int MN[10][10];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < m1; ++j) {
			M[i][j] = rand()%100;
		}
	}
	std::cout << "Output M"<<std::endl;
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < m1; ++j)
			std::cout << M[i][j] << '\t';
		std::cout << std::endl;
	}
	
	for (int i = 0; i < n2; ++i) {
		for (int j = 0; j < m2; ++j) {
			N[i][j] = rand()%100;
		}
	}
	std::cout << std::endl;
	std::cout << "Output N" << std::endl;
	for (int i = 0; i < n2; ++i) {
		for (int j = 0; j < m2; ++j)
			std::cout << N[i][j] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//Сумма
	std::cout << "SUM"<<std::endl;
	if ((n1 == n2) && (m1 == m2)) {
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < m2; ++j)
				std::cout << M[i][j] + N[i][j] << '\t';
			std::cout << std::endl;
		}
	}
	else std::cout << "Dont sum matricks";

	std::cout << std::endl;
	//Разность
	std::cout << "Razn" << std::endl;
	if ((n1 == n2) && (m1 == m2)) {
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < m2; ++j)
				std::cout << M[i][j]-N[i][j] << '\t';
			std::cout << std::endl;
		}
	}
	else std::cout << "Dont raznost matricks";

	std::cout << std::endl;

	//Произведение
	int x = 0;
	
	std::cout << "Proiz" << std::endl;
	if ((n1==m2)&&(m1==n2)){
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			MN[i][j] = 0;
				for (int t = 0; t < n2; t++) {
					MN[i][j] += M[i][t] * N[t][j];
				}	
		}
	}

		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < m1; ++j)
				std::cout << MN[i][j] << '\t';
			std::cout << std::endl;
		}
	}
	else std::cout << "Dont proizvedenie matricks";

	std::cout << std::endl;

	return 0;
}