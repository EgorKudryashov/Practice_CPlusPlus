#include <iostream>
#include <time.h> 
#include <math.h>
#include <cmath>

double f(double x) {
	return (exp(x) * sin(x))/(x*x*x)*(x*x+log(sin(x)* sin(x)* sin(x)* sin(x)+cos(x)* cos(x)* cos(x)* cos(x)));
}
double integralrectangleleft(double x, double x0, int n) {
	double S = 0.0;
	for (int i = 0; i < n; ++i) {
		S += f(x) * x0;
		x += x0;
	}
		return S;	
}
double integralrectangleright(double x, double x0, int n) {
	double S = 0.0;
	for (int i = 0; i < n; ++i) {
		x += x0;
		S += f(x) * x0;
	}
	return S;
}

double integraltrapeze(double x, double x0,int n) {
	double S = 0.0;
	for (int i = 0; i < n; ++i) {
		S += (f(x)+f(x+x0))/2.0 * x0;
		x += x0;
	}
	return S;
}
long double integralCarlo(long double a, long double b, int n) {
	srand((unsigned int)time(NULL));
	long double tmp = b - a;
	long double h = tmp / n;
	long double sum = 0.0;
	long double t;
	for (int i = 1; i <= n; ++i) {
		long double q = (double)rand() / RAND_MAX;
		t = tmp * q + a;
		sum += (f(t) * h);
	}
	return sum;
/*double integralCarlo(double x, double x0, int n,int poi) {
	double maxf=f(x),maxx,minf=f(x),started=x,Smax,ax,ay,coinmax=0.0,coin=0.0,y;
	int k = 0;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; ++i) {
		x += x0;
		if (minf > f(x)) minf = f(x);
		if (maxf < f(x))  maxf = f(x); 
	}   
	Smax = (x - started) * (maxf-minf);
	maxx = x;
	x = started;
	for (int i = 0; i < poi; ++i) {
		ax = rand()*0.1 ;
		ay = rand()*0.1 ;
		if ((ax <= maxx) && (ax >= started) && (ay <= maxf) && (ay >= minf)) {
			coinmax += 1.0;
			k = 0;
			y = f(ax);
			if (y > 0) if (y>ay) coin += 1.0;
			else if (y < ay) coin += 1.0;
			
		}
	}std::cout << coin << " " << coinmax;
	return (Smax * (coin / coinmax));*/
}

int main() {
	double a, b,x0;
	int n,nMC;
	std::cout << "Input a= ";
	std::cin >> a;	
	std::cout << "Input b= ";
	std::cin >> b;
	std::cout << "Range beetween a and b= ";
	std::cin >> n;
	x0 = (b-a)/n;
	std::cout << "rectangle"<<std::endl<<"Left= "<<integralrectangleleft(a,x0,n)<<" and  Right= "<< integralrectangleright(a, x0, n) << std::endl<<std::endl;
	std::cout <<"trapeze= "<<std::endl<<integraltrapeze(a,x0,n)<<std::endl<<std::endl;
	std::cout << "Monte-Carlo= " << integralCarlo(a,b,n)<<std::endl;
	return 0;
}