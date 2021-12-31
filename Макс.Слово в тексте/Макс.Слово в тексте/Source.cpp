#include<iostream>
#include<fstream>
#include<string>

int main() {
	std::ifstream infile;
	infile.open("text.txt");
	if (!infile) {
		std::cout << "can't open File";
		return 0;
	}

	std::string str, maxstr;
	int i=0,imax=0,coll=0;
	char sym;
	do {
		sym = infile.get();
		if (sym>=65 &&sym<=122) {
			++i;
			str += sym;
		}else
		if (((sym < 65) || (sym > 122)) &&(i > imax) && sym!=EOF) {
			maxstr = str;
			imax = i;
			i = 0;
			str = "";
			coll = 1;
		}else if (((sym < 65) || (sym > 122)) && i == imax&& str==maxstr ){
			++coll;
			str = "";
			i = 0;
		}
		else if ((sym < 65) || (sym > 122)){
			str = "";
			i = 0;
		}
	} while (sym != EOF);

	std::cout << maxstr << std::endl << coll;
	infile.close();

	return 0;
}