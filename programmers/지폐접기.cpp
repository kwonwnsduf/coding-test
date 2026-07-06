#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    sort(wallet.begin(), wallet.end());

    while (true) {
        sort(bill.begin(), bill.end());

        if (bill[0] <= wallet[0] && bill[1] <= wallet[1]) {
            break;
        }

        bill[1] /= 2;
        answer++;
    }

    return answer;
}
