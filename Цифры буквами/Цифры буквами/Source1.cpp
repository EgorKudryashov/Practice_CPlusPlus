#include <iostream> 
#include <string>
int main() {
	std::string A[1001];
	std::string B[1];
	long int n, k, y, u;
	std::cin >> n;
	A[0] = '.';
	A[1] = "one ";  A[2] = "two ";  A[3] = "tree ";  A[4] = "four ";  A[5] = "five ";
	A[6] = "six ";  A[7] = "seven ";  A[8] = "eight ";  A[9] = "nine ";  A[10] = "ten ";

	A[11] = "eleven ";  A[12] = "twelve ";  A[13] = "thirteen ";  A[14] = "fourteen ";  A[15] = "fifteen ";

	for (int i = 16; i < 20; ++i) A[i] =  A[i % 10] + "teen ";

	A[20] = "twenty "; A[30] = "thirty "; A[40] = "forty "; A[50] = "fifty ";
	A[60] = "sixty "; A[70] = "seventy "; A[80] = "eighty "; A[90] = "ninety ";
	//22,43,33 и так далее до 99
	for (int i = 21; i < 100; ++i)  A[i] = A[(i / 10) * 10] + A[i % 10];

	A[100] = "hundred ";
	//121,133,422 and td
	for (int i = 101; i < 1000; ++i) A[i] = A[(i / 100)] + A[100] + A[i % 100];

	A[1000] = "thousand ";

	B[0] = " million ";

	if (n <= 999) std::cout << A[n];
	if (n == 1000) std::cout << A[1]+A[1000];
	if ((n > 1000) && (n < 1000000)) std::cout << A[n / 1000] + A[1000] << A[n % 1000];
	else {
		if ((n > 1000000) && (n < 1000000000)) {
			k = n / 1000000;//количество миллионов
			y = (n %1000000)/ 1000;//количество тысяч
			u = n % 1000;
			if (y>0)
			std::cout << A[k] <<B[0] << A[y] << A[1000] << A[u];
			else
			std::cout << A[k] << B[0] << A[y] << A[u];
		}
		else if (n == 1000000) std::cout << A[1] + B[0];
	}


	return 0;

}
