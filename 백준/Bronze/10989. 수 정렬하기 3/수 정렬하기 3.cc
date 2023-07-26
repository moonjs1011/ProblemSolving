#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    map<int,int> m;
    while(T--){
        int input;
        cin>>input;
        if(m.find(input)==m.end())
            m.insert({input,1});
        else m[input]++;
    }
    for(auto e:m)
        for(int i=0;i<e.second;i++)
            cout<<e.first<<"\n";
}