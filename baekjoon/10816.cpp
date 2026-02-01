#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 가속
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    // 1. 상근이가 가진 카드 입력
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    // 2. 이분 탐색을 위한 정렬 (필수!)
    sort(cards.begin(), cards.end());

    // 3. 찾을 숫자들 입력 및 개수 계산
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;

        // lower_bound: target 이상의 값이 처음 나오는 위치의 포인터
        // upper_bound: target 초과의 값이 처음 나오는 위치의 포인터
        auto low = lower_bound(cards.begin(), cards.end(), target);
        auto up = upper_bound(cards.begin(), cards.end(), target);

        // 두 포인터(반환된 반복자)의 차이가 곧 해당 숫자의 개수
        cout << up - low << " ";
    }

    return 0;
}
