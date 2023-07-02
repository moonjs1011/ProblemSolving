#include <iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
vector<int>num;
int arithmetic[4];//+,-,*,/
set<int>result;
int max_value=-1000000001;
int min_value=1000000001;
void dfs(int idx,int res ){
    if(idx==num.size()){
        max_value=max(res,max_value);
        min_value=min(res,min_value);
    }
    else{
        if(arithmetic[0]>0)//+
        {
            arithmetic[0]--;
            dfs(idx+1,res+num[idx]);
            arithmetic[0]++;
        }
        if(arithmetic[1]>0)//+
        {
            arithmetic[1]--;
            dfs(idx+1,res-num[idx]);
            arithmetic[1]++;
        }
        if(arithmetic[2]>0)//+
        {
            arithmetic[2]--;
            dfs(idx+1,res*num[idx]);
            arithmetic[2]++;
        }
        if(arithmetic[3]>0)//+
        {
            arithmetic[3]--;
            dfs(idx+1,int(res/num[idx]));
            arithmetic[3]++;
        }
    }
}
void solve() {
    dfs(1,num[0]);
    cout<<max_value<<"\n"<<min_value<<"\n";
}
int main() {
    int n;
    cin>>n;
    while(n--){
        int input;
        cin>>input;
        num.push_back(input);
    }
    for(int i=0;i<4;i++)
        cin>>arithmetic[i];
    solve();
}


