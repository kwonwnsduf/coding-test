#include <iostream>
#include <string>
#include <vector>

using namespace std;

// S[알파벳][위치]
int p_sum[26][200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();

    // 1. 누적 합 배열 채우기 (전처리)
    for (int i = 0; i < n; i++) {
        int cur_char = s[i] - 'a'; // 알파벳을 0~25 숫자로 변환
        
        for (int j = 0; j < 26; j++) {
            // 이전까지의 합을 그대로 복사
            if (i > 0) p_sum[j][i] = p_sum[j][i - 1];
        }
        // 현재 위치의 알파벳만 +1
        p_sum[cur_char][i]++;
    }

    int q;
    cin >> q;
    while (q--) {
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        int idx = alpha - 'a';
        
        // 2. 구간 합 공식 적용 (l이 0인 경우 주의)
        if (l == 0) {
            cout << p_sum[idx][r] << "\n";
        } else {
            cout << p_sum[idx][r] - p_sum[idx][l - 1] << "\n";
        }
    }

    return 0;
}
