#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0; // cards1에서 현재 가리키는 위치
    int idx2 = 0; // cards2에서 현재 가리키는 위치

    for (const string& word : goal) {
        // 1. cards1의 현재 단어와 일치하는 경우
        if (idx1 < cards1.size() && cards1[idx1] == word) {
            idx1++;
        }
        // 2. cards2의 현재 단어와 일치하는 경우
        else if (idx2 < cards2.size() && cards2[idx2] == word) {
            idx2++;
        }
        // 3. 두 카드 뭉치의 맨 앞 단어 모두 일치하지 않는 경우
        else {
            return "No";
        }
    }

    // goal의 모든 단어를 순서대로 만든 경우
    return "Yes";
}
