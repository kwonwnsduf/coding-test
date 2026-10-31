#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    
    // 1. 정답 배열을 모두 -1로 초기화 (끝까지 짝을 못 찾은 애들은 자연스럽게 -1 유지)
    vector<int> answer(n, -1);
    
    // 2. 짝을 찾지 못한 숫자들의 '인덱스'를 저장할 스택
    stack<int> s; 
    
    for (int i = 0; i < n; i++) {
        // 3. 스택에 대기 중인 숫자들 중 현재 숫자(numbers[i])보다 작은 애들은 모두 털어냄
        while (!s.empty() && numbers[s.top()] < numbers[i]) {
            answer[s.top()] = numbers[i]; // 뒤에 있는 큰 수 기록
            s.pop(); // 짝을 찾았으니 스택에서 제거
        }
        
        // 4. 현재 숫자의 인덱스도 스택에 들어가서 다음 번호들을 대기
        s.push(i);
    }
    
    return answer;
}
