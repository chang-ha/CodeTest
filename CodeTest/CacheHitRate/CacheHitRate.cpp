#include <iostream>
#include <chrono>

const int N = 1024;
int array[N][N];

void accessArrayRowMajor() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = i + j;
        }
    }
}

void accessArrayColumnMajor() {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            array[i][j] = i + j;
        }
    }
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    accessArrayRowMajor();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> rowMajorDuration = end - start;
    std::cout << "Row-major access time: " << rowMajorDuration.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    accessArrayColumnMajor();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> columnMajorDuration = end - start;
    std::cout << "Column-major access time: " << columnMajorDuration.count() << " seconds\n";

    int x = 0;
}