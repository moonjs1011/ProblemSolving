#include <string>
#include <vector>
#include<queue>

#define MAXSIZE 201
using namespace std;
vector<vector<int>> vertex(MAXSIZE);
vector<bool> visited(MAXSIZE, false);

int bfs(int vid) {
    if (visited[vid])
        return 0;
    visited[vid] = true;
    queue<int> q;
    q.push(vid);
    while (!q.empty()) {
        int cur_vid = q.front();
        q.pop();
        for (int i = 0; i < vertex[cur_vid].size(); i++) {
            int next_vid = vertex[cur_vid][i];
            if (!visited[next_vid]) {
                visited[next_vid]=true;
                q.push(next_vid);
            }
        }
    }
    return 1;

}

int solution(int n, vector<vector<int>> computers) {
    //insert vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && computers[i][j] == 1) vertex[i].push_back(j);
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += bfs(i);
    }
    return answer;
}