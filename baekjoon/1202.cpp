#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Jewelry {
    int m, v; // 무게, 가격
};

// 보석은 무게순으로 정렬
bool compare(Jewelry a, Jewelry b) {
    return a.m < b.m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<Jewelry> j(N);
    for (int i = 0; i < N; i++) cin >> j[i].m >> j[i].v;

    vector<int> bags(K);
    for (int i = 0; i < K; i++) cin >> bags[i];

    // 1. 보석과 가방을 모두 무게 기준으로 오름차순 정렬
    sort(j.begin(), j.end(), compare);
    sort(bags.begin(), bags.end());

    priority_queue<int> pq; // 보석의 가격을 담는 최대 힙
    long long total_v = 0;
    int jewel_idx = 0;

    // 2. 가방을 하나씩 확인
    for (int i = 0; i < K; i++) {
        // 현재 가방에 담을 수 있는 모든 보석을 큐에 삽입
        while (jewel_idx < N && j[jewel_idx].m <= bags[i]) {
            pq.push(j[jewel_idx].v);
            jewel_idx++;
        }

        // 3. 큐가 비어있지 않다면 가장 비싼 보석을 가방에 담기
        if (!pq.empty()) {
            total_v += pq.top();
            pq.pop();
        }
    }

    cout << total_v << endl;

    return 0;
}
