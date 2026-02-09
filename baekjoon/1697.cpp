#include <iostream>
#include <queue>

using namespace std;

int N, K;
int dist[100001]; // 방문 여부와 걸린 시간을 동시에 저장

int bfs() {
    queue<int> q;
    q.push(N);
    dist[N] = 1; // 시작 위치 (0초를 1로 표현, 나중에 1 빼기)

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 동생을 찾았다면 시간 반환
        if (cur == K) return dist[cur] - 1;

        // 세 가지 이동 경로 확인
        int next_steps[3] = {cur - 1, cur + 1, cur * 2};
        for (int next : next_steps) {
            // 1. 범위를 벗어나지 않고 2. 아직 방문하지 않았다면
            if (next >= 0 && next <= 100001 && dist[next] == 0) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return 0;
}

int main() {
    cin >> N >> K;
    
    // N과 K가 같을 경우 0초 출력
    if (N == K) {
        cout << 0 << endl;
    } else {
        cout << bfs() << endl;
    }

    return 0;
}
