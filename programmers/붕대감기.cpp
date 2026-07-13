#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> bandage, int max_health, vector<vector<int>> attacks) {
    int t = bandage[0];    // 시전 시간
    int x = bandage[1];    // 초당 회복량
    int y = bandage[2];    // 추가 회복량
    
    // 공격 시간과 데미지를 매핑 (탐색을 빠르게 하기 위함)
    map<int, int> attack_map;
    int last_attack_time = 0;
    for (const auto& attack : attacks) {
        attack_map[attack[0]] = attack[1];
        last_attack_time = max(last_attack_time, attack[0]);
    }
    
    int current_health = max_health;
    int continuous_time = 0; // 연속 성공 시간
    
    // 1초부터 마지막 공격 시간까지 시뮬레이션 진행
    for (int sec = 1; sec <= last_attack_time; ++sec) {
        // 1. 몬스터의 공격이 있는 경우
        if (attack_map.find(sec) != attack_map.end()) {
            current_health -= attack_map[sec];
            continuous_time = 0; // 공격을 받으면 연속 성공 시간 초기화
            
            // 캐릭터 체력이 0 이하가 되면 사망 (-1 반환)
            if (current_health <= 0) {
                return -1;
            }
        } 
        // 2. 몬스터의 공격이 없는 경우 (회복)
        else {
            current_health += x; // 초당 기본 회복
            continuous_time++;   // 연속 성공 시간 증가
            
            // 붕대 감기를 끝까지 성공한 경우
            if (continuous_time == t) {
                current_health += y; // 추가 회복량 획득
                continuous_time = 0; // 연속 성공 시간 초기화
            }
            
            // 최대 체력 초과 방지
            if (current_health > max_health) {
                current_health = max_health;
            }
        }
    }
    
    return current_health;
}
