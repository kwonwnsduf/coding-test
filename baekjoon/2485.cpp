#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대공약수 구하기 (유클리드 호제법)
int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> tree(N);
    vector<int> diff;

    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        if (i > 0) {
            // 인접한 나무 사이의 간격을 저장
            diff.push_back(tree[i] - tree[i - 1]);
        }
    }

    // 1. 모든 간격의 최대공약수 구하기
    int gcd_val = diff[0];
    for (int i = 1; i < diff.size(); i++) {
        gcd_val = get_gcd(gcd_val, diff[i]);
    }

    // 2. 추가로 심어야 할 나무 수 계산
    // 전체 간격 수: (마지막 나무 위치 - 첫 나무 위치) / 공약수
    // 전체 나무 수: 간격 수 + 1
    long long total_trees = (tree[N - 1] - tree[0]) / gcd_val + 1;
    
    // 결과 = 전체 필요한 나무 수 - 현재 있는 나무 수
    cout << total_trees - N << "\n";

    return 0;
}
