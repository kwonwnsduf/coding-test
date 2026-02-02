#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    cin >> N >> C;

    vector<int> house(N);
    for (int i = 0; i < N; i++) {
        cin >> house[i];
    }

    // 1. 이분 탐색을 위해 집 위치 정렬
    sort(house.begin(), house.end());

    // 2. 이분 탐색 범위 설정 (최소 거리, 최대 거리)
    int low = 1; // 가능한 최소 거리
    int high = house[N - 1] - house[0]; // 가능한 최대 거리
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2; // "가장 가까운 거리"의 후보
        
        // 첫 번째 집에는 무조건 공유기를 설치
        int count = 1;
        int last_installed = house[0];

        // 3. mid 거리를 유지하며 공유기를 몇 개 설치할 수 있는지 확인
        for (int i = 1; i < N; i++) {
            if (house[i] - last_installed >= mid) {
                count++;
                last_installed = house[i]; // 설치 위치 갱신
            }
        }

        // 4. 설치 개수에 따른 범위 조정
        if (count >= C) {
            // C개 이상 설치 가능 -> 거리를 더 늘려보자 (최댓값 찾기)
            result = mid;
            low = mid + 1;
        } else {
            // C개를 다 설치 못함 -> 거리를 좁혀야 함
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}
