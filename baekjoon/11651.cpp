#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬 기준을 정의하는 함수
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    // 1. y좌표가 다르면, y좌표가 작은 순서대로(오름차순)
    if (a.second != b.second) {
        return a.second < b.second;
    }
    // 2. y좌표가 같으면, x좌표가 작은 순서대로(오름차순)
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        // 입력은 x, y 순서대로 받음
        cin >> v[i].first >> v[i].second;
    }

    // 세 번째 인자로 우리가 만든 비교 함수 'compare'를 넣어줍니다.
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}
