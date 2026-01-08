#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	// 2. 단어 길이가 긴 순 (내림차순)
	if (a.first.length() != b.first.length()) {
		return a.first.length() > b.first.length();
	}
	// 3. 알파벳 사전 순 (오름차순)
	return a.first < b.first;
}

int main() {
	int N, M;
	cin >> N >> M;
	
	map<string,int> mp;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s.size() >= M) {
			mp[s]++;
		}
	}
	vector<pair<string, int>> words(mp.begin(), mp.end());
	sort(words.begin(), words.end(), cmp);
	for (const auto& p : words) {
		cout << p.first << '\n';
	}
	return 0;

}
