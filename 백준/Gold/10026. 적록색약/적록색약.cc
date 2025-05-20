#include<iostream>
#include<queue>
#include<cstring>

#define MAXSIZE 101
using namespace std;
int N;
char board[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool rangeCheck(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

int bfs(int y, int x, char ch) {
    if (visited[y][x])
        return 0;
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.push({y, x});
    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if (rangeCheck(next_y, next_x) && board[next_y][next_x] == ch && !visited[next_y][next_x]) {
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
        }
    }
    return 1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
    int normal_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            normal_cnt += bfs(i, j, board[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'G') board[i][j] = 'R';
        }
    }
    memset(visited, 0, sizeof(visited));
    int odd_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            odd_cnt += bfs(i, j, board[i][j]);
        }
    }
    cout << normal_cnt << " " << odd_cnt << "\n";
}