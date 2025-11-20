#include <iostream>
#include<vector>
#include<cstring>
#include<queue>
/*
 * 완점 탐색으로 3개의 벽을 세울수 있는 모든 경우를 탐색
 * 이중 for문
 */
#define MAXSIZE 9 //문제에 제시된 최댓값
using namespace std;
int N,M;
int matrix[MAXSIZE][MAXSIZE];
int tempMatrix[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];
int max_cnt=0;
int dy[]={0,0,-1,1};
int dx[]={-1,1,0,0};
vector<pair<int,int>> virus;
vector<pair<int,int>>blank;
bool rangeCheck(int y,int x){ //위치의 범위를 체크
    return y>=0 && y<N && x>=0 && x<M; //탐색 가능한 위치면 true 리턴
}
void bfs(int y,int x){
    queue<pair<int,int>>q;
    q.push({y,x});
    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int next_y =cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(rangeCheck(next_y,next_x)&&tempMatrix[next_y][next_x]==0){
                tempMatrix[next_y][next_x]=2;//감염
                q.push({next_y,next_x});
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==2){//바이러스가 있는 위치
                virus.push_back({i,j});
            }
            else if(matrix[i][j]==0){
                blank.push_back({i,j});
            }
        }
    }
    //blank에서 3개를 뽑는 거
    int B = blank.size();
    for(int i=0;i<B;i++){
        for(int j=i+1;j<B;j++){
            for(int k=j+1;k<B;k++){
                memcpy(tempMatrix,matrix, sizeof(matrix));
                auto pos1 = blank[i];
                auto pos2 = blank[j];
                auto pos3 = blank[k];

                tempMatrix[pos1.first][pos1.second]=1;
                tempMatrix[pos2.first][pos2.second]=1;
                tempMatrix[pos3.first][pos3.second]=1;

                for(auto e : virus){
                    bfs(e.first,e.second);
                }
                int cnt=0;
                for(int y=0;y<N;y++){
                    for(int x=0;x<M;x++){
                        if(tempMatrix[y][x]==0) cnt++;
                    }
                }
                max_cnt = max(max_cnt,cnt);
            }
        }
    }
    cout<<max_cnt<<"\n";
}