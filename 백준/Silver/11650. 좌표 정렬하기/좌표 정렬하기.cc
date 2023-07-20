#include<iostream>
#include<queue>
#include<functional>
using namespace std;
struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second >b.second;
        else return a.first > b.first;
    }
};
int main(){
    int N;
    cin>>N;
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    while(N--){
        int x,y;
        cin>>x>>y;
        pq.push({x,y});
    }
    while(!pq.empty()){
        int top_x = pq.top().first;
        int top_y = pq.top().second;
        cout<<top_x<<" "<<top_y<<"\n";
        pq.pop();
    }
}
