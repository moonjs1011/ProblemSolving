#include<iostream>
#include<queue>
using namespace std;
int M, N, K;
int board[51][51]; // board[i][j] == 1 이면 배추가 심어져있는것, 0이면 아무것도 없는 땅
bool visited[51][51];
int dx[]={-1,1,0,0};// bfs 수행시 탐색을 위한 위치 변화량
int dy[]={0,0,-1,1};//
void clear(){
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++) {
            board[i][j]=0;
            visited[i][j] = false;
        }
    }

}
bool bfs(int y,int x){
    if(visited[y][x] || board[y][x]==0)
        return false;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int next_y = cur_y+dy[i];
            int next_x = cur_x+dx[i];
            if(next_y<0 || next_y>=N || next_y<0 || next_x>=M)
                continue;
            if(board[next_y][next_x] && !visited[next_y][next_x]){
                visited[next_y][next_x] = true;
                q.push({next_y,next_x});
            }
        }
    }
    return true;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int cnt=0;
        cin>>M>>N>>K;
        for(int i=0;i<K;i++){
            int X,Y;
            cin>>X>>Y;
            board[Y][X]=1;
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                    if(bfs(j, i))
                        cnt++;
            }
        }
        cout<<cnt<<"\n";
        clear();
    }
}