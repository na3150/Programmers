#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int>h;
int cnt = 27; //저장할 색인 번호

string findW(string str){
    for (int i = 0; i < str.size(); i++)
    {
        string s = str.substr(0, str.size() - i);
        if (h.count(s)) return s;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    int index = 0;
    for (char i = 'A'; i <= 'Z'; i++) //알파벳 채우기
    {
        string str = "";
        h[str+i] = i - 64;
    }
    while (index < msg.size()) {
        string w = findW(msg.substr(index));
        answer.push_back(h[w]);
        index += w.size();
        h[w + msg[index]] = cnt++; //w+c 사전 추가
    }
    return answer;
}
