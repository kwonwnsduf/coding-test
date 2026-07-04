#include <bits/stdc++.h>
using namespace std;

int toMinute(int time) {
    int hour = time / 100;
    int minute = time % 100;
    return hour * 60 + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < schedules.size(); i++) {
        int limitTime = toMinute(schedules[i]) + 10;
        bool success = true;

        for (int j = 0; j < 7; j++) {
            int day = (startday + j - 1) % 7 + 1;

            if (day == 6 || day == 7) {
                continue;
            }

            int arriveTime = toMinute(timelogs[i][j]);

            if (arriveTime > limitTime) {
                success = false;
                break;
            }
        }

        if (success) {
            answer++;
        }
    }

    return answer;
}
