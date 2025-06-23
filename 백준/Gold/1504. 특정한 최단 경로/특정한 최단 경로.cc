#include<iostream>
#include<vector>
#include<queue>

#define MAXSIZE 801
using namespace std;
int N, E;
vector<vector<pair<int, int>>> adj(MAXSIZE);
const int INF = 1e9;

void insertEdge(int v1, int v2, int w) {
    adj[v1].push_back({v2, w});
    adj[v2].push_back({v1, w});
}

int dijkstra(int v1, int v2) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    dist[v1] = 0;
    q.push({0, v1});
    while (!q.empty()) {
        int cur_cost = q.top().first;
        int cur_vid = q.top().second;
        q.pop();
        if (dist[cur_vid] < cur_cost) continue;
        for (auto [next_vid, weight] : adj[cur_vid]) {
            int next_cost = cur_cost + weight;
            if (dist[next_vid] > next_cost) {
                dist[next_vid] = next_cost;
                q.push({next_cost, next_vid});
            }
        }
    }
    return dist[v2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> E;
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        insertEdge(u, v, w);
    }

    int v1, v2;
    cin >> v1 >> v2;

    int a1 = dijkstra(1, v1);
    int a2 = dijkstra(v1, v2);
    int a3 = dijkstra(v2, N);
    int b1 = dijkstra(1, v2);
    int b2 = dijkstra(v2, v1);
    int b3 = dijkstra(v1, N);

    int path1 = (a1 >= INF || a2 >= INF || a3 >= INF) ? INF : a1 + a2 + a3;
    int path2 = (b1 >= INF || b2 >= INF || b3 >= INF) ? INF : b1 + b2 + b3;

    int ans = min(path1, path2);
    if (ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";
}