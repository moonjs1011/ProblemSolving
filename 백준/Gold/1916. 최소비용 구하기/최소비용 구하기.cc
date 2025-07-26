#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define MAXSIZE 100001
vector<vector<pair<int, int>>> vec(MAXSIZE);
int N, M;

void insert(int v1, int v2, int cost) {
    vec[v1].push_back({v2, cost});;
    return;
}

void bfs(int start, int end) {
    int dict[MAXSIZE];
    for (int i = 1; i <= N; i++) dict[i] = 999999999; //set infinty
    //set start point
    dict[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push({start, 0});
    //do bfs
    while (!q.empty()) {
        int cur_vid = q.top().first;
        int cur_cost = -q.top().second;
        q.pop();
        
        if(dict[cur_vid] < cur_cost) continue;
        for (int i = 0; i < vec[cur_vid].size(); i++) {
            int next_vid = vec[cur_vid][i].first;
            int next_cost = cur_cost + vec[cur_vid][i].second;
            if (dict[next_vid] > next_cost) {
                dict[next_vid] = next_cost;
                q.push({next_vid, -next_cost});
            }
        }
    }
    cout << dict[end] << "\n";
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
    bfs(start, end);
}