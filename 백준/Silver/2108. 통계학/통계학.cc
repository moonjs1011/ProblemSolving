#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int>v;
vector<pair<int,int>>pair_v;
struct Compare{
    bool operator()(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first)
            return a.second<b.second;
        else return a.first>b.first;
    }
};
void insert(int input){
    v.push_back(input);

}
double avg(){
    double sum =0;
    int size = v.size();
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    float res =round(sum/size);
    if(res==-0)
        return 0;
    else return res;
}
int median(){
    return v[v.size()/2];
}
int find(int ele) {
    for(int i=0;i<pair_v.size();i++){
        if(pair_v[i].second==ele)
            return i;
    }
    return -1;
}
int mode(){
    for(int i=0;i<v.size();i++){
        int res;
        if((res=find(v[i]))==-1){
            pair_v.push_back({1,v[i]});
        }
        else{
            pair_v[res] = {pair_v[res].first+1,pair_v[res].second};
        }
    }
    sort(pair_v.begin(),pair_v.end(),Compare());
    if(pair_v.begin()->first==next(pair_v.begin())->first)
        return next(pair_v.begin())->second;
    else return pair_v.begin()->second;
}
int range(){
    return v[v.size()-1] - v[0];
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int input; cin>>input;
        insert(input);
    }
    sort(v.begin(),v.end());
    cout<<avg()<<"\n";
    cout<<median()<<"\n";
    cout<<mode()<<"\n";
    cout<<range()<<"\n";
}

