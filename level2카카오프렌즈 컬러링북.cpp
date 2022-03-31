#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>visited;

int direct[4][2] = { 
    0,1, //��
    0,-1, //��
    1,0, //�Ʒ�
    -1,0 //��
};

int BFS(int x, int y, vector<vector<int>>picture)
{
    int size = 1; //������ ����
    int num = picture[x][y]; //������ ��
    queue<pair<int, int>>queue; //{x,y} ��ǥ
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
            //�迭�� ������ ����� ���
            if (dx < 0 || dy < 0 || dx >= picture.size() || dy >= picture[0].size()) continue;
            //�̹� ���� ��
            if (visited[dx][dy] > 0) continue;
            //���� ������ �ƴ� ���
            if (picture[dx][dy] != num) continue;
            visited[dx][dy] = 1;
            size++;
            queue.push({ dx,dy });
        }
    }
    return size; 
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    visited.assign(m, vector<int>(n,0)); //�ʱ�ȭ
    int number_of_area = 0; //������ ����
    int max_size_of_one_area = -21e8; //�ִ� ���� ����
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