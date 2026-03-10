#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int start = 0, end = 0;
    int sum = 0;
    int min_len = 100001; // 배열 최대 크기보다 큰 값으로 초기화

    while (true) {
        if (sum >= s) {
            // 조건을 만족하면 길이를 재고 start를 당겨서 줄여봄
            min_len = min(min_len, end - start);
            sum -= arr[start++];
        } 
        else if (end == n) {
            // 합이 S보다 작은데 더 이상 더할 숫자가 없으면 종료
            break;
        } 
        else {
            // 합이 S보다 작으면 end를 밀어서 숫자를 더함
            sum += arr[end++];
        }
    }

    if (min_len == 100001) cout << 0 << "\n";
    else cout << min_len << "\n";

    return 0;
}
