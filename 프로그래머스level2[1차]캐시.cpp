#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string>cache; //ĳ�ù迭
unordered_map<string, int>h; //�ؽ� ����

int checkHitOrMiss(string city, int cacheSize) {
    //Hit�� ��
    if (h.count(city) > 0) {
        cache.insert(cache.begin(), city); //�� �տ� �߰�
        auto index = find(cache.begin(), cache.end(), city); 
        cache.erase(index , index+ 1);
        return 1;
    }
    //Miss�� ��
    else { 
        if (cache.size() >= cacheSize) { //ĳ�� ����� �Ѵ� ���
            h.erase(cache[cache.size() - 1]); //�ؽÿ��� ����
            cache.erase(cache.end() - 1);  //������ ���� ����
        }
        cache.insert(cache.begin(), city);
        h[city] = 1;
        return 5;
    }
    return 0;
}


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    //cacheSize�� 0�� ��� ��� Miss
    if (cacheSize == 0)
        return cities.size() * 5;
    //��� �ҹ��ڷ� ��ȯ
    for (int i = 0; i < cities.size(); i++)
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    //�ð� ���
    for (int i = 0; i < cities.size(); i++)
        answer += checkHitOrMiss(cities[i], cacheSize);
    return answer;
}

int main()
{
    int result = solution(5, { "A","B","C","B"});
    cout << result;


	return 0;
}