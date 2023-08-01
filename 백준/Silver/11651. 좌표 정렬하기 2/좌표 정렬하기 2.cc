#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>>v;
struct Compare{
    bool operator()(pair<int,int> a,pair<int,int>b){
        if(a.second==b.second)
            return a.first<b.first;
        else return a.second<b.second;
    }
};
int main(){
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Compare());
    for(auto e :v )
        cout<<e.first<<" "<<e.second<<"\n";
}