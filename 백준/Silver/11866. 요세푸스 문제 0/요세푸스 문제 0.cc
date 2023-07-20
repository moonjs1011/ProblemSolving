#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> solution(vector<int>&v,int K){
    vector<int>res;
    int offset=0;
    while(!v.empty()){
        int size = v.size();
        offset= (offset+(K-1))%size;
        int ele = v[offset];
        res.push_back(ele);
        v.erase(v.begin()+offset);
    }
    return res;
}
void print(vector<int>v){
    cout<<"<";
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i]<<", ";
    }
    cout<<v[v.size()-1]<<">\n";
}
int main(){
    int N,K;
    cin>>N>>K;
    vector<int>v;
    for(int i=1;i<=N;i++){
        v.push_back(i);
    }
    vector<int>res=solution(v,K);
    print(res);
}