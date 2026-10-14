#include <iostream>
#include <iomanip>

int main() {

    int n, m;
    std::cout << "Enter the number of rows (N): ";
    std::cin >> n;
    std::cout << "Enter the number of columns (M): ";
    std::cin >> m;

    double** a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[m];
    }

    int* b = new int[n];

    std::cout << "\nEnter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Row number " << i + 1 << ": ";
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::cout << "\nOriginal matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(4) << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        bool isSymmetric = true;

        for (int j = 0; j < m / 2; j++) {
            if (a[i][j] != a[i][m - 1 - j]) {
                isSymmetric = false;
                break;
            }
        }

        if (isSymmetric) {
            b[i] = 1;
        }
        else {
            b[i] = 0;
        }
    }

    std::cout << "\nFinal array B:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "B[" << i << "] = " << b[i] << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    a = nullptr;

    delete[] b;
    b = nullptr;

    return 0;
}