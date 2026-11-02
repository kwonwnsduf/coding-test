#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    // 몸무게는 100~1000 범위이므로, 인원수를 기록할 배열 선언
    // 큰 수 곱셈 시 오버플로우를 막기 위해 long long 사용
    vector<long long> count(1001, 0); 
    
    // 1. 각 몸무게별 인원수 카운트
    for (int w : weights) {
        count[w]++;
    }
    
    // 2. 100kg부터 1000kg까지 순회하며 짝꿍 찾기
    for (int i = 100; i <= 1000; i++) {
        // 해당 몸무게인 사람이 없으면 패스
        if (count[i] == 0) continue; 
        
        // [비율 1] 1:1 (몸무게가 같은 사람끼리의 짝꿍 수)
        // n명이면 nC2 = n * (n - 1) / 2 쌍이 나옴
        if (count[i] > 1) {
            answer += (count[i] * (count[i] - 1)) / 2;
        }
        
        // [비율 2] 3:4 비율 체크
        // 현재 몸무게가 3으로 나누어 떨어지고, 4/3배 한 값이 1000 이하라면
        if (i % 3 == 0 && (i * 4 / 3) <= 1000) {
            answer += count[i] * count[i * 4 / 3];
        }
        
        // [비율 3] 2:3 비율 체크
        // 현재 몸무게가 2로 나누어 떨어지고, 3/2배 한 값이 1000 이하라면
        if (i % 2 == 0 && (i * 3 / 2) <= 1000) {
            answer += count[i] * count[i * 3 / 2];
        }
        
        // [비율 4] 1:2 (2:4) 비율 체크
        // 현재 몸무게의 2배 한 값이 1000 이하라면
        if ((i * 2) <= 1000) {
            answer += count[i] * count[i * 2];
        }
    }
    
    return answer;
}
