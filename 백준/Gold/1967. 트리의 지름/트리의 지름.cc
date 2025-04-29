#include<iostream>
#include<cstring>
#include<vector>
#define MAXSIZE 10000 + 1
using namespace std;\
struct Node{
    int adj_vid;
    int weight;
    Node(int adj_vid, int weight){
        this->adj_vid = adj_vid;
        this->weight = weight;
    }
};

vector<vector<Node>> adj_list(MAXSIZE);
bool visited[MAXSIZE];
int max_distance=0;
int logest_vid=1;
void insertEdge(int u, int v, int w){
    adj_list[u].push_back(Node(v,w));
    adj_list[v].push_back(Node(u,w));
    return;
}
void dfs(int vid,int distance){
    if(visited[vid])
        return;
    visited[vid] = true;
    for(auto& node : adj_list[vid]){
        dfs(node.adj_vid, distance + node.weight);
    }
    if(max_distance < distance){
        max_distance = distance;
        logest_vid = vid;
    }
}
int main(){
    int N;
    cin>>N;
    while(N>1){
        int parent_vid, child_vid, weight;
        cin>>parent_vid>>child_vid>>weight;
        insertEdge(parent_vid, child_vid, weight);
        N--;
    }
    memset(visited,false,MAXSIZE);
    dfs(1,0);
    memset(visited,false,MAXSIZE);
    dfs(logest_vid,0);
    cout<<max_distance<<"\n";
}
