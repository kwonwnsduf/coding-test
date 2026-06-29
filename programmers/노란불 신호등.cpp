#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int solution(vector<vector<int>> signals) {
    int limit = 1;

    // 전체 패턴이 반복되는 최소공배수 구하기
    for (int i = 0; i < signals.size(); i++) {
        int G = signals[i][0];
        int Y = signals[i][1];
        int R = signals[i][2];

        int cycle = G + Y + R;
        limit = lcm(limit, cycle);
    }

    // 1초부터 전체 반복 주기까지 확인
    for (int t = 1; t <= limit; t++) {
        bool allYellow = true;

        for (int i = 0; i < signals.size(); i++) {
            int G = signals[i][0];
            int Y = signals[i][1];
            int R = signals[i][2];

            int cycle = G + Y + R;

            // t초가 이 신호등의 한 주기 안에서 몇 번째 초인지
            int now = (t - 1) % cycle + 1;

            // 노란불 구간: G+1초부터 G+Y초까지
            if (!(G < now && now <= G + Y)) {
                allYellow = false;
                break;
            }
        }

        if (allYellow) {
            return t;
        }
    }

    return -1;
}
