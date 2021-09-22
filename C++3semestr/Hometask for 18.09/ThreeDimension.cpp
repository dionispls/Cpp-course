#include <iostream>

void print2DArr(int*** arr, size_t rows, size_t cols, size_t third) {
    for(size_t j = 0; j < rows; j++) {
        for(size_t i = 0; i < cols; i++) {
                for(size_t t = 0; t < third; t++) {
                    std::cout << arr[i][j][t] << " ";
                    }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
    }
}
using intptr = int*;
using ptr_to_intptr = intptr*;
using ptr_to_ptr = ptr_to_intptr*;

int main() {

    std::size_t N; //rows
    std::size_t M; //cols
    std::size_t P;

    std::cout << "Enter rows:";
    std::cin >> N;
    std::cout << "Enter columns:";
    std::cin >> M;
    std::cout<<"Enter third dimension:";
    std::cin>> P;
    bool test = 1;
    while(test) {
        ptr_to_ptr a = new ptr_to_intptr[M]; //int** a = new int*[K];
        for(size_t k = 0; k < M; k++) {
            a[k] = new intptr[N];
            for(size_t i = 0; i < N; i++)
                a[k][i] = new int[P];
        }

    for(size_t j = 0; j < N; j++)
        for(size_t i = 0; i < M; i++)
            for(size_t t = 0; t < P; t++)
            a[i][j][t] = i*j*t;

    print2DArr(a, N, M, P);

        for(size_t k = 0; k < M; k++) {
            delete[] a[k];
        }
    delete[] a;
    test = 0;
    }
}
