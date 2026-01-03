#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, int> mp;
    vector<string> result;

    // 1. 듣도 못한 사람 입력
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        mp[name]++;
    }

    // 2. 보도 못한 사람 입력받으며 중복 확인
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        mp[name]++;
        // 값이 2가 되면 양쪽 명단에 모두 있는 사람임
        if (mp[name] == 2) {
            result.push_back(name);
        }
    }

    // 3. 사전 순 출력을 위해 결과 정렬
    sort(result.begin(), result.end());

    // 4. 결과 출력
    cout << result.size() << "\n";
    for (const string& s : result) {
        cout << s << "\n";
    }

    return 0;
}
