#include <iostream>


void found_max_palindrome(char* mas, int ln) {
	int tmp1, tmp2, maxln = 1, k = 1, index1 = -1, tmp = ln - 1;
	for (int i = 0; i < ln; ++i) {
		if (maxln > (ln - i)) break;
		for (int j = tmp; j > i; --j) {
			if (maxln > (j - i)) break;
			tmp1 = i; tmp2 = j;
			k = 1;
			while (mas[tmp1] == mas[tmp2]) {
				if (tmp1 == tmp2 || abs(tmp1 - tmp2) == 1) {
					k = j - i;
					if (k > maxln) maxln = k; index1 = i;
					break;
				}
				tmp1++; tmp2--;
			}
		}
	}
	if (maxln > 1) {
		int index2 = index1 + maxln;
		std::cout<< "The most long palindrom in string    ";
		for (int i = index1; i <= index2; ++i) {
			std::cout << mas[i];
		}
	}
	else {
		std::cout << "Haven't palindrom";
	}
	std::cout << std::endl;
}


int main() {

	char str_array[100];
	std::cout <<"Input string: "<<std:: endl;
	std::cin.getline(str_array, 100);
	int i = 0;
	while (str_array[i]) {
		i++;
	}
	int len = i;
	found_max_palindrome(str_array, len);
	return 0;
}