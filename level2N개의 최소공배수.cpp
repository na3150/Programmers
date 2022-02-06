#include <string>
#include <vector>
using namespace std;

int GCD(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 0; i < arr.size(); i++)
        answer = LCM(answer, arr[i]);
    return answer;
}
