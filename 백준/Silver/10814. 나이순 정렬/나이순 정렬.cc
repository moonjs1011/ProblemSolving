#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    vector<pair<int,pair<int,string>>> v;
    int idx=0;
    while(T--){
        int age;
        string name;
        cin>>age>>name;
        v.push_back({age,{idx,name}});
        idx++;
    }
    sort(v.begin(),v.end());
    for(auto e: v){
        cout<<e.first<<" "<<e.second.second<<"\n";
    }
}