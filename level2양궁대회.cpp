#include <vector>
using namespace std;

vector<pair<int, vector<int>>>results;//{��������, info}
vector<int>lionInfo(11);
vector<vector<int>>sameScores; //�ִ��������� ����
int maxDifferScore;

void checkScore(vector<int>apeachInfo) {
    int lionScore = 0;
    int apeachScore = 0;
    for (int i = 0; i < 11; i++) {
        if (lionInfo[i] > apeachInfo[i]) lionScore += 10 - i;
        else if (apeachInfo[i] > 0) apeachScore += 10 - i;
    }
    int differScore = lionScore - apeachScore;
    if (differScore > 0 && maxDifferScore <= differScore) {
        maxDifferScore = differScore;
        results.push_back({ differScore, lionInfo });
    }
    return;
}

void checkSameScores() {
    while (sameScores.size() > 1) { //�Ѱ��� ���� ������
        for (int i = 10; i >= 0; i--) { //�ڿ������� ��
            if (sameScores[0][i] > sameScores[1][i])
            {
                sameScores.erase(sameScores.begin() + 1);
                break;
            }
            else if (sameScores[0][i] < sameScores[1][i])
            {
                sameScores.erase(sameScores.begin());
                break;
            }
        }
    }
}

void dfs(int now, int sum, int n, vector<int>info) {
    if (sum > n) return;
    if (now == 11 || sum == n) {
        lionInfo[10] = n - sum;
        checkScore(info);
        return;
    }
    //��� ���
    lionInfo[now] = info[now] + 1;
    dfs(now + 1, sum + lionInfo[now], n, info);
    lionInfo[now] = 0;
    //�Ƚ�� ���
    dfs(now + 1, sum, n, info);
}

vector<int> solution(int n, vector<int> info) {
    dfs(0, 0, n, info);
    if (results.size() == 0) return { -1 }; //�̱�� ����� ���� ���
    for (int i = 0; i < results.size(); i++)
        if (maxDifferScore == results[i].first)
            sameScores.push_back(results[i].second); //�������� ���� �͵� ����
    checkSameScores(); //���� ������ ���� ����� ���������� ���
    return sameScores[0];
}
