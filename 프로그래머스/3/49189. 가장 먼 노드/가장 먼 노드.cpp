#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<cmath>

#define MAXSIZE 20001
using namespace std;
vector<vector<int>> adj(MAXSIZE);
int max_dis = 0;

void convert_adj(vector<vector<int>> edge) {
    for (auto &e: edge) {
        int v1 = e[0];
        int v2 = e[1];
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    return;
}

int bfs(int start_vid, int n) {
    int dict[n + 1];
    for (int i = 1; i <= n; i++) {
        dict[i] = 9999999999;
    }
    if (adj[start_vid].empty())
        return 0;
    dict[start_vid] = 0;

    queue<int> q;
    q.push(start_vid);
    while (!q.empty()) {
        int cur_vid = q.front();
        q.pop();
        for (int i = 0; i < adj[cur_vid].size(); i++) {
            int next_vid = adj[cur_vid][i];
            if (dict[next_vid] > dict[cur_vid] + 1) {
                dict[next_vid] = dict[cur_vid] + 1;
                max_dis = max(max_dis, dict[next_vid]);
                q.push(next_vid);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (max_dis == dict[i]) cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    convert_adj(edge);
    answer = bfs(1, n);
    return answer;
}

