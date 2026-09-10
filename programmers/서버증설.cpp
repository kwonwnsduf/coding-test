#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    // expire_servers[t]: t시점에 수명이 다해 반납될 서버의 수
    vector<int> expire_servers(24 + k, 0); 
    int active_servers = 0; // 현재 가동 중인 증설 서버 수

    for (int t = 0; t < 24; ++t) {
        // 1. 현재 시간(t)에 수명이 끝난 서버 반납
        active_servers -= expire_servers[t];

        // 2. 현재 시간대 플레이어 수에 필요한 증설 서버 수 계산
        int needed_servers = players[t] / m;

        // 3. 가동 중인 서버가 부족하면 추가 증설
        if (active_servers < needed_servers) {
            int added = needed_servers - active_servers;
            answer += added;               // 총 증설 횟수 누적
            active_servers += added;       // 현재 가동 서버 수 증가
            expire_servers[t + k] += added; // t + k 시점에 반납 예정 등록
        }
    }

    return answer;
}
