#include<iostream>
#include<vector>
#include<queue>

#define MAX_SIZE 100001
using namespace std;
int ans[MAX_SIZE];

int solution(int n, int k) {
    queue<int> q;    // ~init
    ans[n] = 1;       //
    q.push(n);  //
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (front == k) { // find target
            return ans[front];
        }

        if (front * 2 < MAX_SIZE && ans[front * 2] == 0) {
            ans[front * 2] = ans[front] + 1;
            q.push(front * 2);
        }
        if (front + 1 < MAX_SIZE && ans[front + 1] == 0) {
            ans[front + 1] = ans[front] + 1;
            q.push(front + 1);
        }
        if (front - 1 >= 0 && ans[front - 1] == 0) {
            ans[front - 1] = ans[front] + 1;
            q.push(front - 1);
        }

    }

}


int main() {
    int N, K;
    cin >> N >> K;
    int res = solution(N, K);
    cout << res - 1 << "\n";
}