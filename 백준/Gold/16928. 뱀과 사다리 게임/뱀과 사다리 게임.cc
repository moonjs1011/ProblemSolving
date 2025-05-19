#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<bool> visited(101,0);
vector<int> ladder_snake(101,0);
void bfs(){
    queue<pair<int,int>>q;
    q.push({1,0});
    int min_cost = 100;
    while(!q.empty()){
        int cur_loc = q.front().first;
        int cur_cost = q.front().second;
        q.pop();
        if(cur_loc==100){
            min_cost = min(min_cost,cur_cost);
            continue;
        }
        for(int i=1;i<=6;i++){
            int next_loc = cur_loc + i;
            if(next_loc<=100 && !visited[next_loc]){
                visited[next_loc]=true;
                if(ladder_snake[next_loc]!=0)
                    q.push({ladder_snake[next_loc],cur_cost+1});
                else q.push({cur_loc+i,cur_cost+1});
            }
        }
    }
    cout<<min_cost<<"\n";
}
int main(){
    int N,M;
    cin>>N>>M;
    while(N--){
        int x,y;
        cin>>x>>y;
        ladder_snake[x] = y;
    }
    while(M--){
        int u,v;
        cin>>u>>v;
        ladder_snake[u]=v;
    }
    bfs();
}
