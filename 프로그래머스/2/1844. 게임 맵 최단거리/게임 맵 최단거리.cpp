#include<vector>
#include<cstring>
#include<queue>

using namespace std;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool range_check(int y, int x, int N, int M) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(vector<vector<int>> maps, int target_y, int target_x) {
    int N = maps.size();
    int M = maps[0].size();

    int dict[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dict[i][j] = 999999999;


    dict[0][0] = 1;
    queue<pair<int, pair<int, int>>> q;//{cost,{y_pos,x_pos}}
    q.push({1, {0, 0}});
    while (!q.empty()) {
        int cur_cost = q.front().first;
        int cur_y = q.front().second.first;
        int cur_x = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_cost = cur_cost + 1;
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if (range_check(next_y, next_x, N, M)) {
                if (maps[next_y][next_x] == 1 && dict[next_y][next_x] > next_cost) {
                    dict[next_y][next_x] = next_cost;
                    q.push({next_cost, {next_y, next_x}});
                }
            }
        }
    }
    return (dict[target_y][target_x] != 999999999) ? dict[target_y][target_x] : -1;
}

int solution(vector<vector<int> > maps) {
    int target_y = maps.size() - 1;
    int target_x = maps[0].size() - 1;
    int answer = bfs(maps, target_y, target_x);

    return answer;
}