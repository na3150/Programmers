#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>visited;

int direct[4][2] = { 
    0,1, //우
    0,-1, //좌
    1,0, //아래
    -1,0 //위
};

int BFS(int x, int y, vector<vector<int>>picture)
{
    int size = 1; //영역의 넓이
    int num = picture[x][y]; //영역의 값
    queue<pair<int, int>>queue; //{x,y} 좌표
    queue.push({ x,y });
    visited[x][y] = 1;
    while (!queue.empty())
    {
        int nowX = queue.front().first;
        int nowY = queue.front().second;
        queue.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = nowX + direct[i][0];
            int dy = nowY + direct[i][1];
            //배열의 범위를 벗어나는 경우
            if (dx < 0 || dy < 0 || dx >= picture.size() || dy >= picture[0].size()) continue;
            //이미 지난 곳
            if (visited[dx][dy] > 0) continue;
            //같은 영역이 아닌 경우
            if (picture[dx][dy] != num) continue;
            visited[dx][dy] = 1;
            size++;
            queue.push({ dx,dy });
        }
    }
    return size; 
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    visited.assign(m, vector<int>(n,0)); //초기화
    int number_of_area = 0; //영역의 개수
    int max_size_of_one_area = -21e8; //최대 영역 넓이
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && picture[i][j] > 0)
            {
                int size = BFS(i, j, picture);
                max_size_of_one_area= max(size, max_size_of_one_area);
                number_of_area++;
            }
        }
    vector<int> answer = { number_of_area, max_size_of_one_area };
    return answer;
}