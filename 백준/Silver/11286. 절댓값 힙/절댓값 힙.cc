#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Compare{
    bool operator()(pair<int,int> a, pair<int,int>b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int main(){
    int N;
    cin>>N;
    while(N--){
        int input;
        cin>>input;
        if(input==0){
            if(!pq.empty()) {
                cout << pq.top().second<<"\n";
                pq.pop();
            }
            else cout<<0<<"\n";
        }
        else{
            pq.push({abs(input),input});
        }
    }
}