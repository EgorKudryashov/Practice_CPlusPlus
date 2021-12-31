#include <iostream>
using namespace std;
int main() {
	int a=1,b=2,c=3,d=4,f,n,N;
	cin >> N;
	n = N;
	while (N > 1) {
		if ((N - 4) > 0) {
			N-=4;
			cout << a<<' ' << b<<' ' <<c <<' '<< d<<' ';
			a+=4;
			b+=4;
			c+=4;
			d+=4;
		}
		else {
			f = a;
			if ((N - 1) > 0) { 
				--N;
				cout << f<<' ';
				++a;
			}
		}

	}
	cout << n;

	return 0;
}