#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    // 1. 선수 이름으로 현재 등수(인덱스)를 0(1)만에 찾기 위한 해시맵
    unordered_map<string, int> player_rank;
    for (int i = 0; i < players.size(); i++) {
        player_rank[players[i]] = i;
    }
    
    // 2. 불린 이름(callings)을 순회하며 추월 처리
    for (int i = 0; i < callings.size(); i++) {
        string called_player = callings[i];
        
        int current_rank = player_rank[called_player]; // 불린 선수의 현재 등수
        int front_rank = current_rank - 1;             // 앞 선수의 등수
        
        string front_player = players[front_rank];     // 앞 선수의 이름
        
        // 3. players 벡터에서 두 선수의 위치 교체 (swap)
        players[front_rank] = called_player;
        players[current_rank] = front_player;
        
        // 4. 해시맵의 등수 정보도 갱신
        player_rank[called_player] = front_rank;
        player_rank[front_player] = current_rank;
    }
    
    return players;
}
