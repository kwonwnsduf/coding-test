#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int map[26][26];
bool visited[26][26];
// 상, 하, 좌, 우 이동을 위한 좌표 배열
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int house_count = 0;

void dfs(int x, int y) {
    visited[x][y] = true;
    house_count++; // 현재 단지의 집 개수 증가

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 지도를 벗어나지 않고, 집이 있으며, 아직 방문하지 않은 경우
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (map[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> N;

    // 붙어서 들어오는 숫자 입력을 처리하기 위해 string 사용
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    vector<int> results;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 집이 있고 방문하지 않은 곳 발견 시 DFS 시작
            if (map[i][j] == 1 && !visited[i][j]) {
                house_count = 0; // 초기화
                dfs(i, j);
                results.push_back(house_count);
            }
        }
    }

    // 오름차순 정렬
    sort(results.begin(), results.end());

    cout << results.size() << "\n";
    for (int count : results) {
        cout << count << "\n";
    }

    return 0;
}
