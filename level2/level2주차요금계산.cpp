#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
map<string, int>amountTime; //{������ȣ, �������} -> �ڵ����� ������ȣ �������� ����
vector<vector<pair<string, string>>>inoutTime(10000); //DAT�� ���

void parsingAndInorOut(string str)
{
    int a = str.find(" ");
    int b = str.find(" ", a + 1);
    string time = str.substr(0, 5); //��/���� �ð�
    string carNum = str.substr(a + 1, 4); //���� ��ȣ
    string isInOut = str.substr(b + 1); //����
    int carNumber = stoi(carNum); //������ȣ : string->int
    //����
    if (isInOut == "IN") inoutTime[carNumber].push_back({ time,"" });
    //����
    else inoutTime[carNumber][inoutTime[carNumber].size() - 1].second = time;
    if (amountTime.count(carNum) == 0) amountTime[carNum] = 0; //��� �ȵ� ���
}

void getTime(string carNum, int index) //�����ð� ���
{
    string inTime = inoutTime[stoi(carNum)][index].first;
    string outTime = inoutTime[stoi(carNum)][index].second;
    if (outTime == "") outTime = "23:59"; //�����ð��� ���� ���
    amountTime[carNum] += (stoi(outTime.substr(0, 2)) * 60 + stoi(outTime.substr(3, 2))) - (stoi(inTime.substr(0, 2)) * 60 + stoi(inTime.substr(3, 2)));
}

int getCharge(vector<int>fees, int minute) //��� ���
{
    //�⺻���
    if (minute < fees[0]) return fees[1];
    //�ʰ��Ȱ��
    return fees[1] + ceil((minute - fees[0]) / (double)fees[2]) * fees[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (int i = 0; i < records.size(); i++)
        parsingAndInorOut(records[i]);
    for (auto& k : amountTime)
    {
        //���� �ð� ����ϱ�
        for (int i = 0; i < inoutTime[stoi(k.first)].size(); i++)
            getTime(k.first, i);
        //��� ���
        answer.push_back(getCharge(fees, k.second));
    }
    return answer;
}