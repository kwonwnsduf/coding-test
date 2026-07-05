#include <bits/stdc++.h>
using namespace std;

int toSecond(string time) {
    int minute = stoi(time.substr(0, 2));
    int second = stoi(time.substr(3, 2));
    return minute * 60 + second;
}

string toTime(int totalSecond) {
    int minute = totalSecond / 60;
    int second = totalSecond % 60;

    string mm = minute < 10 ? "0" + to_string(minute) : to_string(minute);
    string ss = second < 10 ? "0" + to_string(second) : to_string(second);

    return mm + ":" + ss;
}

int skipOpening(int pos, int opStart, int opEnd) {
    if (opStart <= pos && pos <= opEnd) {
        return opEnd;
    }
    return pos;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int videoLen = toSecond(video_len);
    int cur = toSecond(pos);
    int opStart = toSecond(op_start);
    int opEnd = toSecond(op_end);

    // 처음 위치가 오프닝 구간이면 오프닝 끝으로 이동
    cur = skipOpening(cur, opStart, opEnd);

    for (string command : commands) {
        if (command == "prev") {
            cur -= 10;

            if (cur < 0) {
                cur = 0;
            }
        } 
        else if (command == "next") {
            cur += 10;

            if (cur > videoLen) {
                cur = videoLen;
            }
        }

        // 명령 실행 후 위치가 오프닝 구간이면 오프닝 끝으로 이동
        cur = skipOpening(cur, opStart, opEnd);
    }

    return toTime(cur);
}
