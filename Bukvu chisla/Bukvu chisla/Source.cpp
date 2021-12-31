#include <iostream>
#include <stack>

std::string hundredsToString(int number) {
	std::string hundredsStrings[]{
			"сто ",
			"двести ",
			"триста ",
			"четыреста ",
			"п€тьсот ",
			"шестьсот ",
			"семьсот ",
			"восемьсот ",
			"дев€тьсот " };
	std::string tensStrings[]{
			"двадцать ",
			"тридцать ",
			"сорок ",
			"п€тьдес€т ",
			"шестьдес€т ",
			"семьдес€т ",
			"восемьдес€т ",
			"дев€носто ",
	};
	std::string onesStrings[]{
			"один ",
			"два ",
			"три ",
			"четыре ",
			"п€ть ",
			"шесть ",
			"семь ",
			"восемь ",
			"дев€ть ",
			"дес€ть ",
			"одиннадцать ",
			"двендцать ",
			"тринадцать ",
			"четырнадцать ",
			"п€тнадцать ",
			"шестнадцать ",
			"семнадцать ",
			"восемнадцать ",
			"дев€тнадцать ",
	};
	std::string result;

	if (number != 0) {
		if (number >= 100) {
			result += hundredsStrings[number / 100 - 1];
		}
		if (number % 100 < 20) {
			result += onesStrings[number % 100 - 1];
		}
		else {
			result += tensStrings[number / 10 % 10 - 2];
			result += onesStrings[number % 10 - 1];
		}
	}

	return result;
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::string order1[]{ "тыс€ча ",
						 "миллион ",
	};
	std::string order2[]{ "тыс€чи ",
						 "миллиона ",
	};
	std::string order3[]{ "тыс€ч ",
						 "миллионов ",
	};


	std::stack<int> numbers;
	int input;

	std::cout << "Enter a number: ";
	std::cin >> input;

	bool isNegative = input < 0;

	input = std::abs(input);
	int inputCache = input;

	while (input != 0) {
		numbers.push(input % 1000);
		input /= 1000;
	}
	int stackSize = numbers.size();

	std::string result;
	if (inputCache == 0) {
		result = "ноль";
	}
	else {
		if (isNegative) {
			result += "минус ";
		}
		for (int i = stackSize - 1; i >= 0; i--) {
			int digits = numbers.top();
			numbers.pop();
			result += hundredsToString(digits);
			if (i != 0 && digits != 0) {
				if (digits % 10 >= 5 || digits % 10 == 0 || (digits % 100 >= 10 && digits % 100 <= 19)) {
					result += order3[i - 1];
				}
				else if (digits % 10 == 1) {
					result += order1[i - 1];
				}
				else {
					result += order2[i - 1];
				}
			}
		}
	}


	std::cout << result << std::endl;

	return 0;
}