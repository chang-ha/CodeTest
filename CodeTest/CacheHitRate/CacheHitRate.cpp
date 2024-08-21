#include <iostream>
#include <chrono>

const int N = 1024;
int array[N][N];

// 열단위로 접근은 확실한 차이를 보임 (캐시 적중률 차이 O)
// 열 단위로 접근은 불연속적 메모리에 접근하기 때문에 캐시 적중률 차이 O
void accessArrayRowMajor() {
    // 캐시 적중률 높음
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = i + j;
        }
    }
}

void accessArrayColumnMajor() {
    // 캐시 적중률 낮음
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

// 같은 행과 열에서 역으로 접근하는건 큰 차이가 없음(캐시 적중률 차이 X)
// CPU 캐시는 블록단위로 데이터를 가져오기 때문에, 역순으로 접근한다 해도 같은 블록에 데이터가 존재하기 때문에 캐시 적중률 차이 X
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

    // 위에서 해당 행렬에 대한 데이터들이 캐시에 올라갔기 때문에, 아래 함수들은 연산이 빠름 (캐시 적중률 높음)
    // 만약 위에 함수들이 먼저 실행되지 않으면 accessArrayForward()의 실행시간은 길어짐
    // 그렇지만 accessArrayReverse()는 여전히 빠름 -> accessArrayForward()함수를 통해 캐시에 메모리가 올라갔기 때문
    // 그래서 두 함수 사이의 캐시 적중률 차이가 존재하는게 아니라 이미 캐시에 데이터가 올라갔냐 차이로 함수 시간이 달라질 수 있음
    // 따라서 한 번 읽어온 데이터에 관련된 내용은 한 번에 처리해야 실행시간 빨라짐
    // -> 다른 데이터들을 또 읽어오다보면 캐시 메모리에서 해당 데이터가 사라져서 캐시 적중률 낮아질 수도 있음
    // ex) anotherArrayAccess(); << 함수 실행하면 앞에서 읽어온 array의 데이터가 캐시에서 내려갈 수 있음 << 캐시 적중률 낮아짐

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