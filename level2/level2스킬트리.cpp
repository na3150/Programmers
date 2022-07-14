#include <unordered_map>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int>m; //��ų ���� ����
    for (int i = 0; i < skill.size(); i++)
        m[skill[i]] = i;

    for (int i = 0; i < skill_trees.size(); i++) {
        int level = 0; //���� ������� ����
        bool flag = true; //���� ����
        for (int j = 0; j < skill_trees[i].size(); j++) {
            if (m.count(skill_trees[i][j]) > 0) { //skill�� ���Ե� ���¶��
                if (level >= m[skill_trees[i][j]]) level++;
                else { //������ ��߳� ���
                    flag = false;
                    break;
                }
            }
        }
        if (flag) answer++;
    }
    return answer;
}
