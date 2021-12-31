#include <iostream>
#include <fstream>
#include <string>

int alphabet(char a) {
    std::string alph = { "abcdefghijklmnopqrstuvwxyz" };
    for (int i = 0; i < 26; ++i) {
        if (alph[i] == a)
            return i;
    }
}
/*
void printArray(int** A, int n, int m) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j)
            std::cout << A[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int digit(int a, int i, int k) {
    for (int j = 0; j < i - 1; ++j) {
        a /= k;
    }
    for (int j = 0; j < i; ++j) {
        a %= k;
    }
    return a;
}
*/

void BubbleSort(int* A, int n, int* ot) {
    bool isSorted;
    for (int j = 0; j < n - 1; ++j) {
        isSorted = true;
        for (int i = n - 1; i > j; --i) {
            if (A[i] < A[i - 1]) {
                std::swap(A[i], A[i - 1]);
                std::swap(A[i + n], A[i + n - 1]);
                std::swap(ot[i], ot[i - 1]);
                isSorted = false;
            }
        }
        if (isSorted) break;
    }
}

void LSDradixSort(int* answer, int** A, int n, int m, int k, int stop) {
    int i, j, st = 0;
    int* B = new int[2 * n];
    int** A_copy;
    A_copy = new int* [n];
    for (int p = 0; p < n; ++p)
        A_copy[p] = new int[m];
    int* ot = new int[n];

    for (i = m - 1; i >= 0; --i) {
        for (int p = 0; p < m; ++p) {
            for (j = 0; j < n; ++j)
                A_copy[j][p] = A[j][p];
        }
        for (j = 0; j < n; ++j) {
            B[j] = A[j][i];
        }
        for (j = 0; j < n; ++j)
            B[j + n] = j;
        for (int p = 0; p < n; ++p)
            ot[p] = answer[p];

        BubbleSort(B, n, ot);

        for (int p = 0; p < m; ++p) {
            for (j = 0; j < n; ++j) {
                A[j][p] = A_copy[B[j + n]][p];
            }
        }
        for (j = 0; j < n; ++j)
            answer[j] = ot[j];

        ++st;
        if (st == stop)
            break;
    }
    delete[] B;
    delete[] ot;
    for (int i = 0; i < n; i++)
        delete[] A_copy[i];
    delete A_copy;
}


int main()
{
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cout << "Don't open File for reading";
        return 1;
    }
    int n, m, k;
    char sym;
    inFile >> n;
    inFile >> m;
    inFile >> k;
    int* order = new int[n];
    for (int i = 0; i < n; ++i) {
        order[i] = i + 1;
    }

    int** M;
    M = new int* [n];
    for (int i = 0; i < n; ++i)
        M[i] = new int[m];

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            inFile >> sym;
            M[i][j] = alphabet(sym);
        }
    }
    inFile.close();

    //printArray(M, n, m);
    LSDradixSort(order, M, n, m, 26, k);
    //printArray(M, n, m);

    std::ofstream outFile;
    outFile.open("output.txt");
    if (!outFile) {
        std::cout << "Don't open File for writing";
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        outFile << order[i];
        outFile << ' ';
    }

    outFile.close();

    for (int i = 0; i < n; i++)
        delete[] M[i];
    delete M;
}

