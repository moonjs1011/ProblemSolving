#include<iostream>
#include<queue>
#define MAXSIZE 10 + 1
using namespace std;
struct INFO{
    int ry,rx;
    int by, bx;
    int count;
};
char board[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE];
int dy[] ={-1,1,0,0};
int dx[] ={0,0,1,-1};
int bfs(INFO start){
    queue<INFO> q;
    q.push(start);
    while(!q.empty()){
        INFO cinfo = q.front();
        int cry = cinfo.ry;
        int crx = cinfo.rx;
        int cby = cinfo.by;
        int cbx = cinfo.bx;
        int ccount = cinfo.count;
        q.pop();
        if(ccount>10) break;
        
        if(board[cry][crx]=='O' && board[cby][cbx]!='O'){
            return ccount;
        }
        if(board[cry][crx]!='O' && board[cby][cbx]=='O') continue;
        
        for(int i=0;i<4;i++){
            int rc=0;// 움직인 거리
            int nry=cry;
            int nrx = crx;
            while(1){ //move red ball
                if(board[nry+dy[i]][nrx+dx[i]]=='#'){
                    break;
                }
                else{
                    nry +=dy[i];
                    nrx +=dx[i];
                    rc++;
                    if(board[nry][nrx]=='O') break;
                }
            }
            int bc=0;
            int nby = cby;
            int nbx = cbx;
            while(1){ //move blue ball
                if(board[nby+dy[i]][nbx+dx[i]]=='#'){
                    break;
                }
                else{
                    nby +=dy[i];
                    nbx +=dx[i];
                    bc++;
                    if(board[nby][nbx]=='O') break;
                }
            }
            if(board[nby][nbx]=='O') continue;
                if(nry == nby && nrx == nbx){ //같은 칸에 있을때
                    if(rc>bc){
                        nry -=dy[i];
                        nrx -=dx[i];
                    }
                    else{
                        nby -=dy[i];
                        nbx -=dx[i];
                    }
                }
            
            if(!visited[nry][nrx][nby][nbx]){
                visited[nry][nrx][nby][nbx]=true;
                q.push({nry,nrx,nby,nbx,ccount+1});
            }
        }
        
        
    }
    return -1;
}
int main(){
    INFO start;
    start.count=0;
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=-0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]=='R'){
                start.ry = i;
                start.rx = j;
            }
            if(board[i][j]=='B'){
                start.by = i;
                start.bx = j;
            }
        }
    }
    cout<<bfs(start)<<"\n";
}
