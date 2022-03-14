#include <string>
#include <bitset>
using namespace std;

string getBinary(int num) { //이진수로 반환하는 함수
    return bitset<8>(num).to_string();
}

int getNumOfOne(string num) { //1의 개수 반환하는 함수
    int cnt = 0;
    for (int i = 0; i < num.size(); i++)
        if (num[i] == '1') cnt++;
    return cnt;
}

int solution(int n) {
    int result = n + 1; //초기 숫자
    int numOfOne = getNumOfOne(getBinary(n)); //n의 1의 개수
    while (1) {
        if (getNumOfOne(getBinary(result)) == numOfOne) 
            break;
        result++;
    }
    return result;
}
