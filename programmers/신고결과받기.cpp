#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_set<string> unique_report(report.begin(), report.end());

    unordered_map<string, int> reported_count;

    // const와 & 없이 그냥 string rep로 써도 똑같이 잘 작동합니다!
    for (string rep : unique_report) {
        stringstream ss(rep);
        string reporter, reported;
        ss >> reporter >> reported;

        reported_count[reported]++;
    }

    unordered_map<string, int> mail_count;

    // 여기도 마찬가지로 그냥 string rep 사용
    for (string rep : unique_report) {
        stringstream ss(rep);
        string reporter, reported;
        ss >> reporter >> reported;

        if (reported_count[reported] >= k) {
            mail_count[reporter]++;
        }
    }

    vector<int> answer;
    // 여기도 string id로 단순화 가능
    for (string id : id_list) {
        answer.push_back(mail_count[id]);
    }

    return answer;
}
