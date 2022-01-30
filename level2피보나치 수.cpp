#include <string>
using namespace std;

long fiboNumber[100001];

int fibo(int n) {
    if (n <= 2) return 1;
    if (fiboNumber[n] != 0) return fiboNumber[n];
    else {
        fiboNumber[n] = (fibo(n - 1) + fibo(n - 2)) % 1234567;
        return fiboNumber[n];
    }
}

int solution(int n) {
    return fibo(n);
}
