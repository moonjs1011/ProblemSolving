#include<iostream>
#include<queue>
using namespace std;
int arr[1001][1001];
int dx[] = { -1,1,0,0 };
int dy[]= { 0,0,-1,1 };
int n, m;
int dst_x, dst_y;
void dijstra(int dst_y, int dst_x) {
	int dist[1001][1001];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				dist[i][j] = 0;
			else
				dist[i][j] = 1000001;
		}
	dist[dst_y][dst_x] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{dst_y,dst_x} });
	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur_y = pq.top().second.first;
		int cur_x = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			if (cur_x + dx[i]<0 || cur_x + dx[i]>m || cur_y + dy[i]<0 || cur_y + dy[i]>n)
				continue;
			if (arr[cur_y + dy[i]][cur_x + dx[i]] == 1) {
				int next_cost = cur_cost + 1;
				int next_y = cur_y + dy[i];
				int next_x = cur_x + dx[i];
				if (dist[next_y][next_x] >next_cost) {
					dist[next_y][next_x] = next_cost;
					pq.push({ -next_cost,{next_y,next_x} });
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 1000001)
				cout << -1 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				dst_y = i;
				dst_x = j;
			}
		}
	dijstra(dst_y, dst_x);
}