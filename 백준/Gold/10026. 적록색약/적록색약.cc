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

int bfs(int y,int x){
    if(visited[y][x]) //이미 방문했을 경우
        return 0;
    visited[y][x] = true;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        int cur_c = board[cur_y][cur_x]; //current_color
        q.pop();
        for(int i=0;i<4;i++){
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(range_check(next_y,next_x) && !visited[next_y][next_x]&&board[next_y][next_x]==cur_c){
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
        }
    }
    memset(visited, false,sizeof(visited));
    int normal_count =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            normal_count+=bfs(i,j);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]=='G')
                board[i][j] ='R';
        }
    }
    memset(visited, false,sizeof(visited));
    int half_count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            half_count+=bfs(i,j);
        }
    }
    cout<<normal_count<<" "<<half_count<<"\n";
}

