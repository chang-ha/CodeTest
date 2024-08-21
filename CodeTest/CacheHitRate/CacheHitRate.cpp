#include <iostream>
#include <chrono>

const int N = 1024;
int array[N][N];

// �������� ������ Ȯ���� ���̸� ���� (ĳ�� ���߷� ���� O)
// �� ������ ������ �ҿ����� �޸𸮿� �����ϱ� ������ ĳ�� ���߷� ���� O
void accessArrayRowMajor() {
    // ĳ�� ���߷� ����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = i + j;
        }
    }
}

void accessArrayColumnMajor() {
    // ĳ�� ���߷� ����
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            array[i][j] = i + j;
        }
    }
}

long long array2[N][N];
long long array3[N][N];
long long array4[N][N];
long long array5[N][N];
long long array6[N][N];
long long array7[N][N];
long long array8[N][N];
long long array9[N][N];
long long array10[N][N];
long long array11[N][N];
long long array12[N][N];
long long array13[N][N];
long long array14[N][N];
long long array15[N][N];
long long array16[N][N];

// ���� ��� ������ ������ �����ϴ°� ū ���̰� ����(ĳ�� ���߷� ���� X)
// CPU ĳ�ô� ��ϴ����� �����͸� �������� ������, �������� �����Ѵ� �ص� ���� ��Ͽ� �����Ͱ� �����ϱ� ������ ĳ�� ���߷� ���� X
void anotherArrayAccess()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            array2[i][j] = 1;
            array3[i][j] = 1;
            array4[i][j] = 1;
            array5[i][j] = 1;
            array6[i][j] = 1;
            array7[i][j] = 1;
            array8[i][j] = 1;
            array9[i][j] = 1;
            array10[i][j] = 1;
            array11[i][j] = 1;
            array12[i][j] = 1;
            array13[i][j] = 1;
            array14[i][j] = 1;
            array15[i][j] = 1;
            array16[i][j] = 1;
        }
    }
}

void accessArrayForward()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = i + j;
        }
    }
}

void accessArrayReverse()
{
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
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

    // ������ �ش� ��Ŀ� ���� �����͵��� ĳ�ÿ� �ö󰬱� ������, �Ʒ� �Լ����� ������ ���� (ĳ�� ���߷� ����)
    // ���� ���� �Լ����� ���� ������� ������ accessArrayForward()�� ����ð��� �����
    // �׷����� accessArrayReverse()�� ������ ���� -> accessArrayForward()�Լ��� ���� ĳ�ÿ� �޸𸮰� �ö󰬱� ����
    // �׷��� �� �Լ� ������ ĳ�� ���߷� ���̰� �����ϴ°� �ƴ϶� �̹� ĳ�ÿ� �����Ͱ� �ö󰬳� ���̷� �Լ� �ð��� �޶��� �� ����
    // ���� �� �� �о�� �����Ϳ� ���õ� ������ �� ���� ó���ؾ� ����ð� ������
    // -> �ٸ� �����͵��� �� �о���ٺ��� ĳ�� �޸𸮿��� �ش� �����Ͱ� ������� ĳ�� ���߷� ������ ���� ����
    // ex) anotherArrayAccess(); << �Լ� �����ϸ� �տ��� �о�� array�� �����Ͱ� ĳ�ÿ��� ������ �� ���� << ĳ�� ���߷� ������

    start = std::chrono::high_resolution_clock::now();
    accessArrayForward();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> ForwardDuration = end - start;
    std::cout << "Forward access time: " << ForwardDuration.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    accessArrayReverse();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> ReverseDuration = end - start;
    std::cout << "Reverse access time: " << ReverseDuration.count() << " seconds\n";

    int x = 0;
}