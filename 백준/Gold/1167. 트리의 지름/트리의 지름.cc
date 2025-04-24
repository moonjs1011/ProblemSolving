#include<iostream>
#include<vector>
#include<string.h>
#define MAXSIZE 100000 + 1
using namespace std;
struct Node{
    int vid;
    int weight;
    Node(int v,int w){
        this->vid = v;
        this->weight = w;
    }
};
int T;
int maxLen = 0;
int maxLenV=1; //vid_1 부터 길이가 가장 긴 노드의 vid
vector<vector<Node>> matrix(MAXSIZE);
bool visited[MAXSIZE];
void dfs(int vid,int distance){
    if(maxLen <distance){
        maxLen = distance;
        maxLenV = vid;
    }
    visited[vid] = true;
    for(auto &node : matrix[vid]){
        if(!visited[node.vid]){
            int next_vid = node.vid;
            int next_distance = node.weight;
            dfs(next_vid,distance + next_distance);
        }
    }
 
}
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int i=1;i<=T;i++){
        int input;
        cin>>input; //vertex id
        int cur_vid = input;
        cin>>input;
        while(input!=-1){
            int adj_vid = input;
            cin>>input;
            int weight =input;
            matrix[cur_vid].push_back(Node(adj_vid,weight));
            cin>>input;
        }
    }
    memset(visited, false, MAXSIZE);
    dfs(1,0);
    memset(visited, false, MAXSIZE);
    maxLen =0;
    dfs(maxLenV,0);
    cout<<maxLen<<"\n";
}
