#include <iostream>
#include <ctime>
int Gause(double** A, int n) {

    double determinant;

    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (A[i][i]) {
                double multiplier = A[j][i] / A[i][i];
                A[j][i]-=multiplier*A[i][i];
                for (int k = i+1; k < n; ++k) {
                    A[j][k] -= multiplier * A[i][k];
                }
            }
        }
    }
    
    int coll = 0;
    if (A[0][0])
    determinant = A[0][0];
    else {
        ++coll;
        for (int k = 1; k < n; ++k) {
            if (A[k][0]) {
                for (int b = 0; b < n; ++b) {
                    double tmp = A[0][b];
                    A[0][b] = A[k][b];
                    A[k][b] = tmp;
                }              
                break;
            }
        }
        if (!A[0][0]) return 0;
        determinant = A[0][0];
    }
    for (int i = 1; i < n; ++i) {
        if (A[i][i]==0.0) {
            ++coll;
            for (int k = i+1; k < n; ++k) {
                if (A[k][i]) {
                    for (int b = i; b < n; ++b) {
                        double tmp = A[i][b];
                        A[i][b] = A[k][b];
                        A[k][b] = tmp;
                    }               
                    break;
                }
            }
        }
        if (!A[i][i]) return 0;
        determinant *= A[i][i];
    }
    if (coll % 2) {
        determinant *= -1;
    }

    return determinant;
}

void Random(double* A[], int n) {
    double c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c = rand() % 10;
            A[i][j] = c;
        }
    }

}

void print(double** A, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(time(0));  
    int n;
    std::cout << "Enter the dimension of the square matrix: ";
    std::cin >> n;
    std::cout << std::endl;
    double** Arr;
    Arr = new double* [n];
    for (int i = 0; i < n; ++i) {
        Arr[i] = new double[n];
    }
    Random(Arr, n);

    std::cout << "Your random matrix:"  << std::endl;
    print(Arr, n);
    std::cout << std::endl;
    std::cout << "Determinant= " << Gause(Arr, n) << std::endl;
    std::cout << std::endl << "Converted Matrix:" << std::endl;
    print(Arr, n);


    for (int i = 0; i < n; ++i) {
        delete Arr[i];
    }
    delete Arr;
    return 0;
}
