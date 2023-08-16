#include<iostream>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int> pq;
    while (N--) {
        int input;
        cin >> input;
        if (input == 0) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                int top = -pq.top();
                pq.pop();
                cout << top << "\n";
            }
        } else pq.push(-input);
    }
}