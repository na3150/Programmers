#include <iostream>
#include <vector>
using namespace std;

int d[501][501];

int solution(vector<vector<int>> triangle) {
    int Max = -21e8;
    int level = triangle.size();
    d[0][0] = triangle[0][0]; //�� �����
    for (int i = 1; i < level; i++)
    {
        //�����ڸ�
        d[i][0] = d[i - 1][0] + triangle[i][0];
        d[i][i] = d[i- 1][i - 1] + triangle[i][i];
        //���
        for (int j = 1; j < i; j++)
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
    }
    //�������ٿ��� �ִ밪 üũ
    for (int i = 0; i < level; i++)
        if (Max < d[level-1][i]) Max = d[level-1][i];
    return Max;
}