#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
map<string, int>amountTime; //{차량번호, 누적요금} -> 자동으로 차량번호 오름차순 정렬
vector<vector<pair<string, string>>>inoutTime(10000); //DAT로 사용

void parsingAndInorOut(string str)
{
    int a = str.find(" ");
    int b = str.find(" ", a + 1);
    string time = str.substr(0, 5); //입/출차 시간
    string carNum = str.substr(a + 1, 4); //차량 번호
    string isInOut = str.substr(b + 1); //내역
    int carNumber = stoi(carNum); //차량번호 : string->int
    //입차
    if (isInOut == "IN") inoutTime[carNumber].push_back({ time,"" });
    //출차
    else inoutTime[carNumber][inoutTime[carNumber].size() - 1].second = time;
    if (amountTime.count(carNum) == 0) amountTime[carNum] = 0; //등록 안된 경우
}

void getTime(string carNum, int index) //누적시간 계산
{
    string inTime = inoutTime[stoi(carNum)][index].first;
    string outTime = inoutTime[stoi(carNum)][index].second;
    if (outTime == "") outTime = "23:59"; //출차시간이 없는 경우
    amountTime[carNum] += (stoi(outTime.substr(0, 2)) * 60 + stoi(outTime.substr(3, 2))) - (stoi(inTime.substr(0, 2)) * 60 + stoi(inTime.substr(3, 2)));
}

int getCharge(vector<int>fees, int minute) //요금 계산
{
    //기본요금
    if (minute < fees[0]) return fees[1];
    //초과된경우
    return fees[1] + ceil((minute - fees[0]) / (double)fees[2]) * fees[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (int i = 0; i < records.size(); i++)
        parsingAndInorOut(records[i]);
    for (auto& k : amountTime)
    {
        //누적 시간 계산하기
        for (int i = 0; i < inoutTime[stoi(k.first)].size(); i++)
            getTime(k.first, i);
        //요금 계산
        answer.push_back(getCharge(fees, k.second));
    }
    return answer;
}