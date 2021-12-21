#include <string>
#include <bitset>
using namespace std;

string getBinary(int num) { //�������� ��ȯ�ϴ� �Լ�
    return bitset<8>(num).to_string();
}

int getNumOfOne(string num) { //1�� ���� ��ȯ�ϴ� �Լ�
    int cnt = 0;
    for (int i = 0; i < num.size(); i++)
        if (num[i] == '1') cnt++;
    return cnt;
}

int solution(int n) {
    int result = n + 1; //�ʱ� ����
    int numOfOne = getNumOfOne(getBinary(n)); //n�� 1�� ����
    while (1) {
        if (getNumOfOne(getBinary(result)) == numOfOne) break;
        result++;
    }
    return result;
}