#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>>map; 

//�ð���� ȸ�� �� �ּڰ� ����
int rotateAndGetMin(int x1, int y1, int x2, int y2) {
    int backup = map[x1][y1];
    int Min = backup;
    for (int i = x1 + 1; i <= x2; i++) //���� ����
    {
        map[i - 1][y1] = map[i][y1];
        Min = min(Min, map[i][y1]);
    }
    for (int i = y1+1; i <= y2; i++) //�Ʒ��� ����
    {
        map[x2][i - 1] = map[x2][i];
        Min = min(Min, map[x2][i]);
    }
    for (int i = x2; i > x1; i--) { //������ ����
        map[i][y2] = map[i - 1][y2];
        Min = min(Min, map[i - 1][y2]);
    }
    for (int i = y2; i > y1+1; i--) { //���� ����
        map[x1][i] = map[x1][i - 1];
        Min = min(Min, map[x1][i - 1]);
     }
    map[x1][y1 + 1] = backup;
    return Min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    //map �ʱ�ȭ
    map.assign(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            map[i][j] = i*columns + j+1;
    //ȸ���� �ּڰ�
    for (int i = 0; i < queries.size(); i++)
        answer.push_back(rotateAndGetMin(queries[i][0]-1, queries[i][1]-1, queries[i][2]-1, queries[i][3]-1));
    return answer;
}

int main()
{
    vector<int>result = solution(100, 97, { { 1,1,100,97} });
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}