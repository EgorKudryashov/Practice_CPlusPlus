#include <iostream> 
using namespace std;

int main()
{
	int n, k;
	int arr[500];
	for (int i = 0; i < 500; i++) {
		arr[i] = 0;
	}
	cin >> n >>k;
	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}
	int peop = n, flag = 1;
	while (peop != 1) {
		for (int i = 0; i < n; i++) {
			if (flag == k && arr[i] == 1) {
				arr[i] = 0;
				flag = 1;
				--peop;
			}
			else if (arr[i] == 1) {
				++flag;
			}
			if (peop == 1) break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			cout << i+1 ;
		}
	}
}