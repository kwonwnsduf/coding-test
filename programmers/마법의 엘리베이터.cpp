#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    // 층수가 0이 될 때까지 반복
    while (storey > 0) {
        int digit = storey % 10;           // 현재 일의 자리 숫자
        int next_digit = (storey / 10) % 10; // 그 다음 앞자리 숫자
        
        if (digit < 5) {
            // 5 미만이면 그냥 빼는 것이 이득 (내림)
            answer += digit;
            storey /= 10;
        } 
        else if (digit > 5) {
            // 5 초과면 더해서 10을 만드는 것이 이득 (올림)
            answer += (10 - digit);
            storey = storey / 10 + 1; // 앞자리에 1을 더해줌 (올림 발생)
        } 
        else { 
            // 정확히 5인 경우, 앞자리 숫자를 보고 판단
            answer += 5;
            if (next_digit >= 5) {
                storey = storey / 10 + 1; // 앞자리가 크면 같이 올려버리는 게 이득
            } else {
                storey /= 10;             // 앞자리가 작으면 내림
            }
        }
    }
    
    return answer;
}
