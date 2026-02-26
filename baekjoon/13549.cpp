#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
const int INF = 1e9;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> dist(MAX, INF);
    // {시간, 위치} 저장하는 최소 힙
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[N] = 0;
    pq.push({0, N});

    while (!pq.empty()) {
        int time = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (curr == K) {
            cout << time << endl;
            return 0;
        }

        if (dist[curr] < time) continue;

        // 1. 순간이동 (가중치 0)
        if (curr * 2 < MAX && dist[curr * 2] > time) {
            dist[curr * 2] = time;
            pq.push({time, curr * 2});
        }

        // 2. 걷기 (+1) (가중치 1)
        if (curr + 1 < MAX && dist[curr + 1] > time + 1) {
            dist[curr + 1] = time + 1;
            pq.push({time + 1, curr + 1});
        }

        // 3. 걷기 (-1) (가중치 1)
        if (curr - 1 >= 0 && dist[curr - 1] > time + 1) {
            dist[curr - 1] = time + 1;
            pq.push({time + 1, curr - 1});
        }
    }

    return 0;
}
