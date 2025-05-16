#include <iostream>
#include <vector>
using namespace std;

#define MAXSIZE 100001

int N, R, Q;
vector<vector<int>> vertex(MAXSIZE);
int dp[MAXSIZE];
bool visited[MAXSIZE];

int dfs(int node, int parent) {
    dp[node] = 1; // 자기 자신 포함
    for (int next_node : vertex[node]) {
        if (next_node == parent) continue;
        dp[node] += dfs(next_node, node);
    }
    return dp[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }

    dfs(R, -1);

    while (Q--) {
        int U;
        cin >> U;
        cout << dp[U] << "\n";
    }

    return 0;
}