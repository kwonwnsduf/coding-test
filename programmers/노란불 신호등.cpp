#include <string>
#include <vector>
#include <numeric> // gcd
using namespace std;

class Solution {
public:
    int solution(vector<vector<int>> signals) {
        int limit = 1;

        // 모든 신호등 주기의 최소공배수 구하기
        for (auto signal : signals) {
            int cycle = signal[0] + signal[1] + signal[2];
            limit = lcm(limit, cycle);
        }

        // 1초부터 전체 반복 주기까지 확인
        for (int t = 1; t <= limit; t++) {
            bool allYellow = true;

            for (auto signal : signals) {
                int G = signal[0];
                int Y = signal[1];
                int R = signal[2];

                int cycle = G + Y + R;

                // 현재 시간이 이 신호등의 한 주기 안에서 몇 번째 초인지
                int now = (t - 1) % cycle + 1;

                // 노란불 구간이 아니면 실패
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

private:
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
};#include <string>
#include <vector>
#include <numeric> // gcd
using namespace std;

class Solution {
public:
    int solution(vector<vector<int>> signals) {
        int limit = 1;

        // 모든 신호등 주기의 최소공배수 구하기
        for (auto signal : signals) {
            int cycle = signal[0] + signal[1] + signal[2];
            limit = lcm(limit, cycle);
        }

        // 1초부터 전체 반복 주기까지 확인
        for (int t = 1; t <= limit; t++) {
            bool allYellow = true;

            for (auto signal : signals) {
                int G = signal[0];
                int Y = signal[1];
                int R = signal[2];

                int cycle = G + Y + R;

                // 현재 시간이 이 신호등의 한 주기 안에서 몇 번째 초인지
                int now = (t - 1) % cycle + 1;

                // 노란불 구간이 아니면 실패
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

private:
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
};
