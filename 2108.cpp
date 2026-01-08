#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    int count[8001] = {0}; // -4000 ~ 4000 빈도 저장
    double sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum += v[i];
        count[v[i] + 4000]++; // 음수 인덱스 방지를 위해 4000을 더함
    }

    sort(v.begin(), v.end());

    // 1. 산술평균
    int avg = round(sum / N);
    if (avg == -0) avg = 0; // -0.33 같은 경우 -0이 출력될 수 있음 방지
    cout << avg << "\n";

    // 2. 중앙값
    cout << v[N / 2] << "\n";

    // 3. 최빈값
    int max_freq = 0;
    for (int i = 0; i < 8001; i++) {
        if (count[i] > max_freq) max_freq = count[i];
    }

    vector<int> modes;
    for (int i = 0; i < 8001; i++) {
        if (count[i] == max_freq) {
            modes.push_back(i - 4000);
        }
    }

    if (modes.size() > 1) {
        cout << modes[1] << "\n"; // 두 번째로 작은 값
    } else {
        cout << modes[0] << "\n";
    }

    // 4. 범위
    cout << v.back() - v.front() << "\n";

    return 0;
}
