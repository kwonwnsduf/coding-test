#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// "HH:MM" 문자열을 분 단위 정수로 변환하는 함수
int timeToInt(const string& t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times;
    
    for (const auto& book : book_time) {
        int start = timeToInt(book[0]);
        int end = timeToInt(book[1]) + 10; // 퇴실 시간에 청소 시간 10분 추가
        times.push_back({start, end});
    }
    
    // 입실 시간을 기준으로 오름차순 정렬
    sort(times.begin(), times.end());
    
    // 사용 중인 객실의 종료 시간을 관리할 최소 힙 (가장 빠른 종료 시간이 top에 옴)
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (const auto& time : times) {
        int start = time.first;
        int end = time.second;
        
        // 기존 객실을 이어서 사용할 수 있는 경우 (큐의 가장 빠른 종료 시간 <= 현재 입실 시간)
        if (!pq.empty() && pq.top() <= start) {
            pq.pop(); // 해당 객실 재사용
        }
        
        // 새로운 종료 시간 갱신 (새 객실을 할당하거나 기존 객실의 시간 연장)
        pq.push(end);
    }
    
    // 우선순위 큐에 남아있는 요소의 개수가 필요한 최소 객실 수
    return pq.size();
}#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// "HH:MM" 문자열을 분 단위 정수로 변환하는 함수
int timeToInt(const string& t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times;
    
    for (const auto& book : book_time) {
        int start = timeToInt(book[0]);
        int end = timeToInt(book[1]) + 10; // 퇴실 시간에 청소 시간 10분 추가
        times.push_back({start, end});
    }
    
    // 입실 시간을 기준으로 오름차순 정렬
    sort(times.begin(), times.end());
    
    // 사용 중인 객실의 종료 시간을 관리할 최소 힙 (가장 빠른 종료 시간이 top에 옴)
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (const auto& time : times) {
        int start = time.first;
        int end = time.second;
        
        // 기존 객실을 이어서 사용할 수 있는 경우 (큐의 가장 빠른 종료 시간 <= 현재 입실 시간)
        if (!pq.empty() && pq.top() <= start) {
            pq.pop(); // 해당 객실 재사용
        }
        
        // 새로운 종료 시간 갱신 (새 객실을 할당하거나 기존 객실의 시간 연장)
        pq.push(end);
    }
    
    // 우선순위 큐에 남아있는 요소의 개수가 필요한 최소 객실 수
    return pq.size();
}
