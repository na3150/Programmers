#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<pair<int, int>>sameBlocks; //2X2내의 좌표 저장(중복X)

bool compare(pair<int, int > a, pair<int, int>b) {
    return a.second > b.second;
}

void putCoordinates(int x, int y) { //set에 4개의 좌표 첨가
    for (int i = x; i < x + 2; i++)
        for (int j = y; j < y+2; j++)
            sameBlocks.insert({ i,j });
}

bool isHaveSameBlocks(vector<vector<string>>map) {
    for (int i = 0; i < map.size() - 1; i++)
    {
        if (map[i].size() == 0) continue;
        for (int j = 0; j < map[i].size() - 1; j++)
        {
            if (map[i + 1].size() > j + 1)
            {
                string a = map[i][j];
                string b = map[i + 1][j];
                string c = map[i][j + 1];
                string d = map[i + 1][j + 1];
                if (a == b && a == c && a == d) putCoordinates(i, j);
            }
        }
    }
    return sameBlocks.size() == 0 ? false : true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<string>>map(n, vector<string>(m));//오른쪽으로 90도 회전된 배열
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            map[i][j] = board[m - j - 1][n - i- 1];
    
    while (isHaveSameBlocks(map)) { //같은 블럭이 안 나올 때 까지
        vector<pair<int, int>>results(sameBlocks.begin(), sameBlocks.end());
        sort(results.begin(), results.end(), compare); //정렬
        for (auto it : results) //2X2 블럭 지우기
            map[it.first].erase(map[it.first].begin() + it.second );
        answer += sameBlocks.size();
        sameBlocks.clear();
    }
    return answer; 
}
