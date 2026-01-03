#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    // 1. 입출력 속도 향상 (데이터가 많으므로 필수!)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 번호로 이름을 찾기 위한 벡터 (1번부터 시작하므로 크기를 n+1로 설정)
    vector<string> numToName(n + 1);
    // 이름으로 번호를 찾기 위한 해시맵
    unordered_map<string, int> nameToNum;

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        numToName[i] = name;
        nameToNum[name] = i;
    }

    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;

        // 입력의 첫 글자가 숫자인지 확인
        if (isdigit(query[0])) {
            // 숫자라면: 문자열을 정수로 바꾸고 벡터에서 찾기
            int num = stoi(query);
            cout << numToName[num] << "\n";
        } else {
            // 문자라면: 맵에서 찾기
            cout << nameToNum[query] << "\n";
        }
    }

    return 0;
}
