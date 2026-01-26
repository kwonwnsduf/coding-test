#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> dist(N - 1); // 도시 사이의 거리
    vector<long long> price(N);    // 각 도시의 주유소 가격

    for (int i = 0; i < N - 1; i++) cin >> dist[i];
    for (int i = 0; i < N; i++) cin >> price[i];

    long long total_cost = 0;
    // 현재까지 발견한 가장 저렴한 주유 가격 (첫 번째 도시 가격으로 초기화)
    long long min_price = price[0];

    for (int i = 0; i < N - 1; i++) {
        // 현재 도시의 가격이 지금까지의 최저가보다 싸다면 업데이트
        if (price[i] < min_price) {
            min_price = price[i];
        }
        
        // 최저가 * 다음 도시까지의 거리
        total_cost += (min_price * dist[i]);
    }

    cout << total_cost << endl;

    return 0;
}
