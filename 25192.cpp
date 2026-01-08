#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<set>
using namespace std;


int main() {
	int N;
	cin >> N;
	set<string> s;
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "ENTER") {
			cnt += s.size();
			s.clear();
		}
		else {
			s.insert(str);
		}
	
	}
	cout << cnt + s.size() << endl;
}
