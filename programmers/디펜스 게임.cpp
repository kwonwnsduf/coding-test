#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq; // 기본값이 최대 힙(Max-Heap)
    
    // 만약 무적권의 수가 전체 라운드 수보다 크거나 같다면 무조건 끝까지 클리어 가능
    if (k >= enemy.size()) {
        return enemy.size();
    }
    
    for (int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]); // 현재 라운드의 적을 힙에 추가
        n -= enemy[i];     // 일단 병사를 소모해서 방어
        
        // 병사가 부족해진 경우
        if (n < 0) {
            // 무적권이 남아있다면, 지금까지 겪은 가장 큰 적 그룹에 무적권 사용
            if (k > 0) {
                n += pq.top(); // 소모했던 병사 복구
                pq.pop();      // 해당 라운드는 무적권으로 방어했으므로 힙에서 제거
                k--;           // 무적권 1개 소모
            } else {
                // 병사도 없고 무적권도 없다면 여기서 게임 오버
                return i;
            }
        }
    }
    
    // 모든 라운드를 막아냈을 경우
    return enemy.size();
}
