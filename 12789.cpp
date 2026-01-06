#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // 0부터 N-1까지 입력받기
    }

    stack<int> s;
    int target = 1; // 지금 간식 먹어야 하는 번호

    for (int i = 0; i < N; i++) {
        // 1. 현재 줄의 학생이 target이면 바로 통과
        if (arr[i] == target) {
            target++;
        } 
        else {
            // 2. 아니면 스택으로 보냄
            s.push(arr[i]);
        }

        // 3. 스택의 top이 target이면 계속 꺼내줌 (핵심!)
        while (!s.empty() && s.top() == target) {
            s.pop();
            target++;
        }
    }

    // 모든 학생을 처리한 후, target이 N+1까지 갔다면 모두 성공
    if (target == N + 1)
        cout << "Nice" << endl;
    else
        cout << "Sad" << endl;

    return 0;
}
