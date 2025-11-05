#include <string>
#include <vector>
#include<iostream>
using namespace std;
/*
Maxsize = 50
1. 50 by 50 matrix 생성 
2. rectangle 배열 돌면서 모든 점을 1로 마스킹
3. rectangle 배열 돌면서 속을 파낸다.
*/
bool valid[102][102];
bool visited[102][102];
int min_cnt = 99999999;

int dy[] ={-1,1,0,0};
int dx[] = {0,0,-1,1};

void mask_path(vector<vector<int>>rectangle){
    //2. rectangle 배열 돌면서 모든 점을 1로 마스킹
    for(vector<int> points : rectangle){
        int x1=2*points[0];//좌측하단 x 좌표
        int y1 = 2*points[1];//좌측 하단 y 좌표
        int x2 = 2*points[2]; //우측 상단 x 좌표
        int y2 = 2*points[3]; //우측 상단 y 좌표
        for(int x = x1; x<=x2;x++){
            for(int y = y1; y<=y2; y++){
                valid[x][y] = 1; 
            }
        }
    }
    //3. rectangle 배열 돌면서 속을 파낸다.
        for(vector<int> points : rectangle){
        int x1=2*points[0];//좌측하단 x 좌표
        int y1 = 2*points[1];//좌측 하단 y 좌표
        int x2 = 2*points[2]; //우측 상단 x 좌표
        int y2 = 2*points[3]; //우측 상단 y 좌표
        for(int x = x1+1; x<=x2-1;x++){
            for(int y = y1+1; y<=y2-1; y++){
                valid[x][y] = 0;
            }
        }
    }
}
void dfs(int cx,int cy,int ix,int iy,int cnt){
    if(cx==ix && cy == iy){
        min_cnt = min(min_cnt,cnt);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(valid[nx][ny] && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx,ny,ix,iy,cnt+1);
            visited[nx][ny] =false;
        }
    }
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    mask_path(rectangle);
    dfs(2*characterX,2*characterY,2*itemX,2*itemY,0);
    return min_cnt/2;
}