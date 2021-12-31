#include <iostream>

int number_of_end_palindrome(char* mas, int len) {
	int j, k;
	for (int i = 0; i < len; i++) {
		j = len - 1;
		k = i;
		while (mas[k] == mas[j]) {
			if (k == j || abs(j - k) == 1) return i - 1;
			k++; j--;
		}
	}
	return len - 2;
}

int main() {


	char str_array[100];
	std::cout << "Input string" << std::endl;
	std::cin.getline(str_array, 100);
	int i = 0;
	while (str_array[i]) {
		i++;
	}
	int len = i;
	int start = number_of_end_palindrome(str_array, len);
	std::cout << std::endl;
	std::cout << str_array;
	for (i = start; i >= 0; --i) {
		std::cout << str_array[i];
	}
	std::cout << std::endl;
}