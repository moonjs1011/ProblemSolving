#include <iostream>
#include <stack>
using namespace std;

// 우선순위 함수 정의
int precedence(char op) {
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string expr;
    cin >> expr;
    stack<char> op;

    for(char c : expr) {
        if(c >= 'A' && c <= 'Z') {
            cout << c;
        }
        else if(c == '(') {
            op.push(c);
        }
        else if(c == ')') {
            while(!op.empty() && op.top() != '(') {
                cout << op.top();
                op.pop();
            }
            if(!op.empty()) op.pop(); // '(' 제거
        }
        else { // 연산자
            while(!op.empty() && precedence(op.top()) >= precedence(c)) {
                cout << op.top();
                op.pop();
            }
            op.push(c);
        }
    }

    while(!op.empty()) {
        cout << op.top();
        op.pop();
    }

    return 0;
}