#include <string>
#include <vector>
using namespace std;

int visited[8];
int Max = -21e8;

void dfs(int level, int pirodo, vector<vector<int>> dungeons) {
    if (level > Max) Max = level; 

    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] == 1) continue;
        if (pirodo < dungeons[i][0]) continue;
        visited[i] = 1;
        dfs(level + 1,pirodo - dungeons[i][1], dungeons);
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return Max;
}
