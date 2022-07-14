#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string>cache; //캐시배열
unordered_map<string, int>h; //해시 생성

int checkHitOrMiss(string city, int cacheSize) {
    //Hit일 때
    if (h.count(city) > 0) {
        cache.insert(cache.begin(), city); //맨 앞에 추가
        auto index = find(cache.begin(), cache.end(), city); 
        cache.erase(index , index+ 1);
        return 1;
    }
    //Miss일 때
    else { 
        if (cache.size() >= cacheSize) { //캐쉬 사이즈를 넘는 경우
            h.erase(cache[cache.size() - 1]); 
            cache.erase(cache.end() - 1); 
        }
        cache.insert(cache.begin(), city);
        h[city] = 1;
        return 5;
    }
}


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    //cacheSize가 0인 경우 모두 Miss
    if (cacheSize == 0)
        return cities.size() * 5;
    //모두 소문자로 변환
    for (int i = 0; i < cities.size(); i++)
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    //시간 계산
    for (int i = 0; i < cities.size(); i++)
        answer += checkHitOrMiss(cities[i], cacheSize);
    return answer;
}
