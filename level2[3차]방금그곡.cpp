#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> getMusicInfos(string musicinfo) //musicinfo를 파싱 후 vector로 반환
{
    vector<string>result;
    result.push_back(musicinfo.substr(0, 5)); //재생 시작 시간
    result.push_back(musicinfo.substr(6, 5)); //종료 시간
    int index = musicinfo.find(",", 12);
    result.push_back(musicinfo.substr(12, index - 12)); //음악 제목
    result.push_back(musicinfo.substr(index + 1)); //악보 정보
    return result;
}

int getTime(string start, string end) //음악 재생 시간 반환
{
    int sh = stoi(start.substr(0, 2));
    int eh = stoi(end.substr(0, 2));
    int sm = stoi(start.substr(3, 2));
    int em = stoi(end.substr(3, 2));
    return (eh * 60 + em) - (sh * 60 + sm);
}

string getPlayedMusic(int time, string music) //재생된 음악(멜로디) 반환
{
    string playedMusic = "";
    int playedTime = 0;
    int index = 0;
    int len = music.length();
    while (playedTime < time)
    {
        playedMusic += music[(len + index++) % len];
        if (music[(len + index) % len] == '#') {
            playedMusic += '#';
            index++;
        }
        playedTime++;
    }
    return playedMusic;
}

bool compare(pair<int, string>a, pair<int, string> b) //재생시간 긴 순서로 내림차순
{
    if (a.first != b.first) return a.first > b.first;
}

bool isRight(string m, string playedMusic) //찾는 음악이 맞는지 확인
{
    int start = 0;
    while (start < playedMusic.length())
    {
        start = playedMusic.find(m, start);
        if (start < 0) return false;
        if (playedMusic[start + m.length()] != '#') return true; //발견되면 바로 true
        start += m.length();
    }
}

string solution(string m, vector<string> musicinfos) {
    vector<pair<int, string>>results; //{재생시간, 음악제목}
    for (int i = 0; i < musicinfos.size(); i++)
    {
        vector<string>musicinfo = getMusicInfos(musicinfos[i]);
        int time = getTime(musicinfo[0], musicinfo[1]);
        string playedMusic = getPlayedMusic(time, musicinfo[3]);
        int index = playedMusic.find(m);
        if (isRight(m, playedMusic)) results.push_back({ time,musicinfo[2] });
    }
    if (results.size() == 0) return "(None)"; //조건을 만족하는 음악이 없는 경우
    sort(results.begin(), results.end(), compare);
    return results[0].second;
}