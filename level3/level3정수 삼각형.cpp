#include <iostream>
#include <vector>
using namespace std;

int d[501][501];

int solution(vector<vector<int>> triangle) {
    int Max = -21e8;
    int level = triangle.size();
    d[0][0] = triangle[0][0]; //맨 꼭대기
    for (int i = 1; i < level; i++)
    {
        //가장자리
        d[i][0] = d[i - 1][0] + triangle[i][0];
        d[i][i] = d[i- 1][i - 1] + triangle[i][i];
        //가운데
        for (int j = 1; j < i; j++)
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
    }
    //마지막줄에서 최대값 체크
    for (int i = 0; i < level; i++)
        if (Max < d[level-1][i]) Max = d[level-1][i];
    return Max;
}