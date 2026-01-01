#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main() {
    int N;
    cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        // 첫 번째 단어이거나, 이전 단어와 다를 때만 출력!
        if (i == 0 || v[i] != v[i - 1]) {
            cout << v[i] << "\n";
        }
    }
    return 0;
}
