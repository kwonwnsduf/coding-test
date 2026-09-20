#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0, right = 0;
    long long sum = sequence[0];
    
    int ans_left = 0, ans_right = n; // 최적의 구간을 저장할 변수
    
    while (left <= right && right < n) {
        if (sum == k) {
            // 현재 찾은 구간의 길이가 기존보다 짧다면 갱신
            if (right - left < ans_right - ans_left) {
                ans_left = left;
                ans_right = right;
            }
            // 다음 탐색을 위해 왼쪽 포인터 이동
            sum -= sequence[left];
            left++;
        } 
        else if (sum < k) {
            right++;
            if (right < n) {
                sum += sequence[right];
            }
        } 
        else { // sum > k
            sum -= sequence[left];
            left++;
        }
    }
    
    return {ans_left, ans_right};
}
