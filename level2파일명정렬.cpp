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
    //head ��
    for (int i = 0; i < before.length(); i++) {
        if (isdigit(before[i])) {
            blasthead = i;
            break; }
        bhead += tolower(before[i]);//�ҹ��ڷ� ��ȯ
    }
    for (int i = 0; i < after.length(); i++) {
        if (isdigit(after[i])) { 
            alasthead = i;
            break; }
        ahead += tolower(after[i]);
    }
    if (bhead != ahead) return bhead < ahead;
    //number ��
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
    //head�� number�� ���� ���
    return 0;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);
    return files;
}


int main()
{
    vector<string>result = solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}