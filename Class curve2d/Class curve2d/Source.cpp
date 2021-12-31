#include <iostream>
#include <vector>
//a_11*x^2+a12*xy+a22*y^2+a13*x+a23*y+a33=0
//  0       1*      2       3*     4*      5

class Curve2d {
	std::vector<double> koef;
public:
	Curve2d(const std::vector<double> &a) {
		koef.resize(6);
		for (int i = 0; i < 6; ++i) {
			koef[i] = a[i];//koef.push_back(a[i]); тогда можно обойтись без resize
		}
	}

	double J2() const {
		return koef[0] * koef[2] - koef[1]/2 * koef[1]/2;
	}

	double J3() const {
		return koef[0] * koef[2] * koef[5] + koef[1] * koef[3]/2 * koef[4]/2 - koef[3]/2 * koef[3]/2 * koef[2] - koef[4]/2 * koef[4]/2 * koef[0] - koef[1]/2 * koef[1]/2 * koef[5];
	}

	double operator()  (const double x, const double y) const  {
		return koef[0] * x* x + koef[1] * x * y + koef[2] * y * y + koef[3] * x + koef[4] * y + koef[5] ;
	}
	// метод для вывода функции на экран вида f(x,y)=x^2+y+1(к примеру) 
	void print() const {
		std::cout << "f(x,y)=";
		if (koef[0] == 1) std::cout << "x^2"; else if (koef[0] != 0) std::cout << koef[0] << "x^2";
		if (koef[1] > 0) std::cout << "+"; if (koef[1] == 1) std::cout << "xy"; else if (koef[1]!=0) std::cout << koef[1] << "xy";
		if (koef[2] > 0) std::cout << "+"; if (koef[2] == 1) std::cout << "y^2"; else if (koef[2] != 0) std::cout << koef[2] << "y^2";
		if (koef[3] > 0) std::cout << "+"; if (koef[3] == 1) std::cout << "x"; else if (koef[3] != 0) std::cout << koef[3] << "x";
		if (koef[4] > 0) std::cout << "+"; if (koef[4] == 1) std::cout << "y"; else  if (koef[4] != 0)std::cout << koef[4] << "y";
		if (koef[5] > 0) std::cout << "+" ; if (koef[5] != 0) std::cout << koef[5];
	}

};

int main() {
	
	double c;
	std::vector < double> a;
	std::cout << "input 6 koefficientof for krivoy:  ";
	for (int i = 0; i < 6; ++i) {
		std::cin >> c;
		a.push_back(c);
	}
	Curve2d f(a);

	std::cout << "J2= " << f.J2() << ",  J3= " << f.J3() << std::endl;
	double x1, y1;
	std::cout << "Input x, y: ";
	std::cin >> x1;
	std::cin >> y1;
	std::cout <<"in point (x,y) f="<< f(x1, y1)<<'\n';
	f.print();
	return 0;
}