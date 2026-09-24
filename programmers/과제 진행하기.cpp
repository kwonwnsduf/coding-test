#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Task {
    string name;
    int start;
    int playtime;
};

// 시작 시간 기준 정렬
bool cmp(const Task& a, const Task& b) {
    return a.start < b.start;
}

// "hh:mm" -> 분 단위 변환
int convertTime(string t) {
    int hour = stoi(t.substr(0, 2));
    int minute = stoi(t.substr(3, 2));
    return hour * 60 + minute;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Task> tasks;

    for (int i = 0; i < plans.size(); i++) {
        tasks.push_back({plans[i][0], convertTime(plans[i][1]), stoi(plans[i][2])});
    }

    sort(tasks.begin(), tasks.end(), cmp);

    stack<Task> st; // 멈춘 과제 보관 (name, start(미사용), playtime)
    
    int current_time = 0;
    int i = 0;
    int n = tasks.size();

    while (i < n || !st.empty()) {
        // 1. 더 이상 시작할 새 과제가 없다면, 스택에 남은 멈춘 과제들을 마저 처리
        if (i >= n) {
            auto top_task = st.top();
            st.pop();
            answer.push_back(top_task.name);
            continue;
        }

        // 2. 현재 시각이 다음 과제 시작 시각보다 앞서 있다면, 스택의 멈춘 과제를 꺼내서 처리
        if (current_time < tasks[i].start && !st.empty()) {
            auto top_task = st.top();
            st.pop();

            int available_time = tasks[i].start - current_time; // 다음 과제 시작까지 남은 시간

            if (top_task.playtime <= available_time) {
                current_time += top_task.playtime; // 과제 완료에 걸린 시간 만큼 현재 시각 진행
                answer.push_back(top_task.name);
            } else {
                top_task.playtime -= available_time;
                st.push(top_task);
                current_time = tasks[i].start; // 다음 과제 시작 시각으로 점프
            }
        } 
        // 3. 스택에 멈춘 과제가 없거나, 현재 시각이 이미 다음 과제 시작 시각에 도달한 경우
        else {
            current_time = max(current_time, tasks[i].start);
            st.push(tasks[i]); // 일단 스택에 넣고(가장 최근에 시작한 과제가 위로 가도록)
            i++;               // 다음 과제로 이동
            
            // 방금 넣은 과제를 바로 꺼내서 진행 상태로 관리하기 위해 
            // 스택의 top을 현재 진행 중인 과제처럼 다룸
            // (위의 push와 아래 pop 구조를 다듬은 형태)
        }
    }

    return answer;
}
