#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (getline(cin, s) && s != ".") {
        stack<char> st;
        bool isBalanced = true;

        for (char c : s) {
            // 1. 여는 괄호는 스택에 저장
            if (c == '(' || c == '[') {
                st.push(c);
            }
            // 2. 소괄호 닫기
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    isBalanced = false;
                    break;
                }
                st.pop();
            }
            // 3. 대괄호 닫기
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    isBalanced = false;
                    break;
                }
                st.pop();
            }
        }

        // 4. 결과 출력 (균형이 맞고 스택이 비어있어야 함)
        if (isBalanced && st.empty()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
