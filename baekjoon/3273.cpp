#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    // 1. 오름차순 정렬
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;
    int count = 0;

    // 2. 투 포인터 탐색
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == x) {
            count++;
            left++;
            right--;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << count << "\n";

    return 0;
}
