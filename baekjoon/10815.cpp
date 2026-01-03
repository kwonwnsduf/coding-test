#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, val;
    cin >> N;
    unordered_set<int> s;
    for(int i=0; i<N; i++) {
        cin >> val;
        s.insert(val);
    }

    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> val;
        if(s.find(val) != s.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }
}
