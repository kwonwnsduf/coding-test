#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> oil(m, 0);

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {

            if (land[y][x] == 0 || visited[y][x])
                continue;

            queue<pair<int, int>> q;
            q.push({y, x});
            visited[y][x] = true;

            int size = 0;
            set<int> columns;

            while (!q.empty()) {
                auto [cy, cx] = q.front();
                q.pop();

                size++;
                columns.insert(cx);

                for (int d = 0; d < 4; d++) {
                    int ny = cy + dy[d];
                    int nx = cx + dx[d];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;

                    if (visited[ny][nx] || land[ny][nx] == 0)
                        continue;

                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }

            // 이 석유 덩어리가 걸쳐 있는 모든 열에
            // 덩어리 전체 크기를 더한다.
            for (int col : columns) {
                oil[col] += size;
            }
        }
    }

    return *max_element(oil.begin(), oil.end());
}
