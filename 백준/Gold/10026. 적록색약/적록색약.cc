#include <iostream>
#include<cstring>
#include<queue>
#define MAXSIZE 101
using namespace std;
int N;
char board[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];
int dy[]={-1,1,0,0};
int dx[] = {0,0,1,-1};
vector<vector<pair<int,int>>>rgb(3); //위치 저장
//범위 체크
bool range_check(int y,int x){
    return y>=0 && y<N && x>=0 && x<N;
}
//BFS1(적록색약 아닌 사람)
int bfs1(int y,int x,char color){
    if(visited[y][x]) //이미 방문했을 경우
        return 0;
    visited[y][x] = true;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(range_check(next_y,next_x) && !visited[next_y][next_x]&&board[next_y][next_x]==color){
                visited[next_y][next_x]=true;
                q.push({next_y,next_x});
            }
        }
    }
    return 1;
}
//BFS2(적록색약인 사람)
int main(){
    //Input board info
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]=='R')
                rgb[0].push_back({i,j});
            if(board[i][j]=='G')
                rgb[1].push_back({i,j});
            if(board[i][j]=='B')
                rgb[2].push_back({i,j});
        }
    }
    memset(visited, false,sizeof(visited));
    int r=0;
    for(int i=0;i<rgb[0].size();i++)
        r+=bfs1(rgb[0][i].first,rgb[0][i].second,'R');

    int g=0;
    for(int i=0;i<rgb[1].size();i++)
        g+=bfs1(rgb[1][i].first,rgb[1][i].second,'G');

    int b=0;
    for(int i=0;i<rgb[2].size();i++)
        b+=bfs1(rgb[2][i].first,rgb[2][i].second,'B');
    cout<<r+g+b<<" ";
    memset(visited, false,sizeof(visited));
    for(int i=0;i<rgb[1].size();i++)
        board[rgb[1][i].first][rgb[1][i].second] = 'R'; // board에 있는 모든 G를 R로 바꿈
        
    r = 0;
    for(int i=0;i<rgb[0].size();i++)
        r+=bfs1(rgb[0][i].first,rgb[0][i].second,'R');
    
    for(int i=0;i<rgb[1].size();i++){
        r+=bfs1(rgb[1][i].first,rgb[1][i].second,'R');
    }
    
    b=0;
    for(int i=0;i<rgb[2].size();i++)
        b+=bfs1(rgb[2][i].first,rgb[2][i].second,'B');
    cout<<r+b;
}

