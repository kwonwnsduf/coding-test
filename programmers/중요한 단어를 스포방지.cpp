#include <bits/stdc++.h>
using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int n = message.size();

    vector<int> cover(n, 0);

    for (auto range : spoiler_ranges) {
        int start = range[0];
        int end = range[1];

        for (int i = start; i <= end; i++) {
            cover[i] = 1;
        }
    }

    set<string> normalWords;
    vector<string> spoilerWords;

    int i = 0;

    while (i < n) {
        if (message[i] == ' ') {
            i++;
            continue;
        }

        int start = i;
        string word = "";
        bool isSpoilerWord = false;

        while (i < n && message[i] != ' ') {
            word += message[i];

            if (cover[i] == 1) {
                isSpoilerWord = true;
            }

            i++;
        }

        if (isSpoilerWord) {
            spoilerWords.push_back(word);
        } else {
            normalWords.insert(word);
        }
    }

    int answer = 0;

    set<string> openedSpoilerWords;

    for (string word : spoilerWords) {
        if (normalWords.count(word)) {
            continue;
        }

        if (openedSpoilerWords.count(word)) {
            continue;
        }

        answer++;
        openedSpoilerWords.insert(word);
    }

    return answer;
}
