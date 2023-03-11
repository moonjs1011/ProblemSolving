#include<iostream>
#include<vector>
#include <queue>
#define MAXSIZE 100001
using namespace std;

vector<vector<int>>v(MAXSIZE);
int par[MAXSIZE];
bool visited[MAXSIZE];
void bfs(int v1) {
	queue<int>q;
	q.push(v1);
	visited[v1] = true;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < v[parent].size(); i++) {
			if (visited[v[parent][i]] == false) {
				q.push(v[parent][i]);
				visited[parent] = true;
				par[v[parent][i]] = parent;
			}
		}
	}
	
}
int main() {
	int N;
	cin >> N;
	for(int i=0;i<N-1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	bfs(1);
	for (int i = 2; i <= N; i++)
		cout << par[i] << "\n";
}