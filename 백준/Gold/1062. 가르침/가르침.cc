//
// Created by Sung_1 on 2023/07/05.
//
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<string> v;
int N,K;
bool Alpabet[26];
int max_cnt=0;
int check_count(){
    int cnt=0;
    for(int i=0;i<v.size();i++){
        bool flag=true;
        for(int j=0;j<v[i].size();j++){
            if(!Alpabet[v[i][j]-'a']){
                flag=false;
                break;
            }
        }
        if(flag){
            cnt++;
        }
    }
    return cnt;
}
void dfs(int index,int cnt){
    if(cnt==K){
        int num = check_count();
        max_cnt=max(max_cnt,num);
        return;
    }
    else{
        for(int i=index;i<26;i++){
            if(Alpabet[i]) continue;
            Alpabet[i]=true;
            dfs(i,cnt+1);
            Alpabet[i]=false;
        }
    }
}
void solve() {
    if(K<5){
        cout<<0<<"\n";
        return;
    }
   Alpabet['a'-'a']=true;
   Alpabet['n'-'a']=true;
   Alpabet['t'-'a']=true;
   Alpabet['i'-'a']=true;
   Alpabet['c'-'a']=true;
   K=K-5;
   dfs(0,0);
   cout<<max_cnt;
}
int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        string input;
        cin>>input;
        v.push_back(input);
    }
    solve();
}