#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    // 입출력 가속 (백준 필수)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0; // N 입력 예외 처리

    vector<pair<int, int>> vec;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }

    sort(vec.begin(), vec.end(), compare);

    int cnt = 1;
    int current_end = vec[0].second; // 첫 번째 회의의 종료 시간

    for (int i = 1; i < N; i++) {
        // [수정 포인트] vec[i].first(시작 시간)가 current_end(이전 종료 시간)보다 크거나 같아야 함
        if (vec[i].first >= current_end) {
            cnt++;
            current_end = vec[i].second; // 종료 시간 업데이트
        }
    }
    cout << cnt << endl;

    return 0;
}
