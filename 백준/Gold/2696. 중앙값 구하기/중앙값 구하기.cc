#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int line=1;
void sol(vector<int> v){
    if(line%10==0){
        cout<<"\n";
        line=0;
    }
    int start_idx = 0;
    int end_idx = v.size()-1;
    if(v.size()%2==1)
        cout<<v[(end_idx-start_idx)/2]<<" ";
    else{
        int middle = (v[(end_idx-start_idx)/2]+ v[(end_idx-start_idx)/2-1])/2;
        cout<<middle<<" ";
        line++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int M;cin>>M;
        vector<int> v;
        int idx=0;
        if(M%2==0)
            cout<<M/2<<"\n";
        else cout<<M/2+1<<"\n";
        for(int i=1;i<=M;i++){
            int input;cin>>input;
            v.push_back(input);
            if(i%2==1){
                sort(v.begin(),v.end());
                sol(v);
            }
        }
        cout<<"\n";
    }
}