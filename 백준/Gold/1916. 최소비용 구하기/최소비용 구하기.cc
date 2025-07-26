#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define MAXSIZE 100001
vector<vector<pair<int, int>>> vec(MAXSIZE);
int N, M;

void insert(int v1, int v2, int cost) {
    vec[v1].push_back({v2, cost});
}

void dijkstra(int start, int end) {
    vector<int> dist(N + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start}); // {cost, vertex}

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_vid = pq.top().second;
        pq.pop();

        if (dist[cur_vid] < cur_cost) continue; // 이미 더 짧은 거리로 방문했으면 스킵

        for (auto &[next_vid, edge_cost] : vec[cur_vid]) {
            int next_cost = cur_cost + edge_cost;
            if (dist[next_vid] > next_cost) {
                dist[next_vid] = next_cost;
                pq.push({next_cost, next_vid});
            }
        }
    }

    cout << dist[end] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    while (M--) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        insert(v1, v2, cost);
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start, end);
}