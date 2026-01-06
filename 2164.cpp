#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    queue<int> q;

    // 1부터 N까지 카드 쌓기
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    // 카드가 한 장 남을 때까지 반복
    while (q.size() > 1) {
        // 1. 맨 위 카드 버리기
        q.pop();
        
        // 2. 그다음 맨 위 카드를 맨 아래로 옮기기
        if (q.size() == 1) break; // 버린 직후 한 장 남았으면 종료
        
        int top_card = q.front();
        q.push(top_card);
        q.pop();
    }

    // 마지막 남은 카드 출력
    cout << q.front() << endl;

    return 0;
}
