#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> expire_times; // 각 증설 서버의 만료 시각(t + k)을 저장하는 큐

    for (int t = 0; t < 24; ++t) {
        // 1. 현재 시간(t)에 만료된 서버 반납 처리
        while (!expire_times.empty() && expire_times.front() <= t) {
            expire_times.pop();
        }

        // 2. 현재 시간대에 필요한 증설 서버 수
        int needed_servers = players[t] / m;

        // 3. 현재 가동 중인 서버 수(= 큐의 크기)가 부족하면 추가 증설
        int active_servers = expire_times.size();
        if (active_servers < needed_servers) {
            int added = needed_servers - active_servers;
            answer += added;
            
            // 부족한 수만큼 t + k 만료 시각을 큐에 추가
            for (int i = 0; i < added; ++i) {
                expire_times.push(t + k);
            }
        }
    }

    return answer;
}
