#include <string>
#include <vector>
using namespace std;

string change_num(int num, int n) {
    string value = "0123456789ABCDEF";
    string str = "";
    while (num / n != 0) {
        str = value[num % n] + str;
        num =  num / n;
    }
    str = value[num % n] + str;
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string result = "";
    for (int i = 0; i < t * m; i++)
        result += change_num(i, n);
    int index = p-1; //p¹øÂ°
    while (answer.length() < t)
    {
        answer += result[index];
        index += m;
    }
    return answer;
}