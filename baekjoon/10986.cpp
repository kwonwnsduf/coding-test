#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long> remain(M, 0); // 나머지들의 개수를 저장할 배열
    long long sum = 0;
    long long count = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
        
        int r = sum % M;
        if (r == 0) count++; // 0부터 i까지의 합이 이미 M으로 나누어떨어지는 경우
        
        remain[r]++; // 나머지별로 개수를 카운트
    }

    // 나머지가 같은 지점들 중 2개를 선택하는 조합 계산 (nC2)
    for (int i = 0; i < M; i++) {
        if (remain[i] > 1) {
            count += (remain[i] * (remain[i] - 1)) / 2;
        }
    }

    cout << count << endl;

    return 0;
}
