/*#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	set <string> answer;
	vector<string> sorting;
	vector<string> fin;
	ifstream infile ("anagram.txt");

	string s = "";
	int l; cin >> l;
	getline(infile, s);
	while (!infile.eof()) {
		getline(infile, s);
		string temp = "";
		for (int i = 0; i < s.length(); ++i) {
			temp += s[i];
		}
		if (temp.length() == l) {
			fin.push_back(temp);
			sorting.push_back(temp);
			temp = "";
		}
	}
	for (int i = 0; i < sorting.size(); ++i) {
		sort(sorting[i].begin(), sorting[i].end());
	}
	bool flag = false;
	for (int i{ 0 }; i < fin.size() - 1; ++i) {
		for (int j = i + 1; j < fin.size(); ++j) {
			if (sorting[i] == sorting[j]) {
				flag = true;
				if (flag == true) {
					answer.insert(fin[i]);
					answer.insert(fin[j]);
				}

			}
		}
	}
	if (flag == false)
		cout << "No anagrams of such length";
	else {
		for (auto now : answer) {
			cout << now << endl;
		}
	}
	return 0;
}*/

#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::ifstream infile;
	infile.open("input.txt");
	if (!infile) {
		std::cout << "Can not open input file" << std::endl;
	}
	std::ofstream outfile;
	outfile.open("output.txt");
	if (!outfile) {
		std::cout << "Can not open output file" << std::endl;
	}
	std::vector <std::vector <char>> slova;
	std::vector <std::vector <char>> anagramms;
	int l;
	infile >> l;
	char str[1000];
	while (infile.getline(str, 1000)) {
		if (strlen(str) == l) {
			std::vector <char> vec;
			for (int i = 0; i < l; ++i) {
				vec.push_back(str[i]);
			}
			slova.push_back(vec);
			for (int i = 0; i < vec.size(); ++i) {
				for (int j = 0; j < vec.size(); ++j) {
					if (vec[i] < vec[j]) {
						std::swap(vec[i], vec[j]);
					}
				}
			}
			bool flag = true;
			for (int i = 0; i < anagramms.size(); ++i) {
				if (anagramms[i] == vec) {
					flag = false;
				}
			}
			if (flag) {
				anagramms.push_back(vec);
			}
		}
	}
	std::vector <std::pair<std::vector <char>, std::vector<char>>> anagISlovo;
	for (int i = 0; i < slova.size(); ++i) {
		std::vector <char> sup;
		sup = slova[i];
		for (int i = 0; i < sup.size(); ++i) {
			for (int j = 0; j < sup.size(); ++j) {
				if (sup[i] < sup[j]) {
					std::swap(sup[i], sup[j]);
				}
			}
		}
		anagISlovo.push_back(std::make_pair(sup, slova[i]));
	}
	for (int i = 0; i < anagISlovo.size(); ++i) {
		for (int j = 0; j < anagISlovo.size(); ++j) {
			if (anagISlovo[i].first < anagISlovo[j].first) {
				std::swap(anagISlovo[i], anagISlovo[j]);
			}
		}
	}
	std::vector <std::vector <char>> itog;
	for (int j = 0; j < anagISlovo.size() - 1; ++j) {
		std::vector <char> vec1 = anagISlovo[j].first;
		std::vector <char> vec2 = anagISlovo[j + 1].first;
		if (vec1 == vec2) {
			itog.push_back(anagISlovo[j].second);
		}
		while (vec1 == vec2) {
			itog.push_back(anagISlovo[j + 1].second);
			++j;
			vec1 = anagISlovo[j].first;
			vec2 = anagISlovo[j + 1].first;
		}
		bool flag = false;
		for (int i = 0; i < itog.size(); ++i) {
			for (int k = 0; k < itog[i].size(); ++k) {
				outfile << itog[i][k];
			}
			outfile <<' ';
			flag = true;
		}
		if (flag) { outfile << std::endl; }
		while (itog.size()) { itog.pop_back(); }
		/*for (int i = 0; i < anagISlovo[j].second.size(); ++i) {
			outfile << anagISlovo[j].second[i];
		}
		outfile << ' ';
	} else {
		outfile << std::endl;
		for (int i = 0; i < anagISlovo[j].second.size(); ++i) {
			outfile << anagISlovo[j].second[i];
		}
		outfile << ' ';*/
	}
	infile.close();
	outfile.close();
	return 0;
}