#include <unordered_map>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int>m; //스킬 순서 저장
    for (int i = 0; i < skill.size(); i++)
        m[skill[i]] = i;

    for (int i = 0; i < skill_trees.size(); i++) {
        int level = 0; //현재 사용자의 레벨
        bool flag = true; //성공 여부
        for (int j = 0; j < skill_trees[i].size(); j++) {
            if (m.count(skill_trees[i][j]) > 0) { //skill에 포함된 강좌라면
                if (level >= m[skill_trees[i][j]]) level++;
                else { //순서에 어긋난 경우
                    flag = false;
                    break;
                }
            }
        }
        if (flag) answer++;
    }
    return answer;
}
