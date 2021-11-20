#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string before, string after) {
    string bhead = "";
    string ahead = "";
    string bnum = "";
    string anum = "";
    int blasthead=0, alasthead=0;
    //head 비교
    for (int i = 0; i < before.length(); i++) {
        if (isdigit(before[i])) {
            blasthead = i;
            break; }
        bhead += tolower(before[i]);//소문자로 변환
    }
    for (int i = 0; i < after.length(); i++) {
        if (isdigit(after[i])) { 
            alasthead = i;
            break; }
        ahead += tolower(after[i]);
    }
    if (bhead != ahead) return bhead < ahead;
    //number 비교
    for (int i = blasthead; i < before.length(); i++)
    {
        if (isdigit(before[i]))  bnum += before[i];
        else break;
    }
    for (int i = alasthead; i < after.length(); i++)
    {
        if (isdigit(after[i])) anum += after[i];
        else break;
    }
    if (stoi(bnum) != stoi(anum)) return stoi(bnum) < stoi(anum);
    //head와 number가 같은 경우
    return 0;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);
    return files;
}
