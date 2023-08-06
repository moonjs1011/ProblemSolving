#include<iostream>
#include<vector>
using namespace std;
int * dp_function(){
    int *dp = new int [11];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 11; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp;
}

int main(){
    int *ans = dp_function();
    int T;
    cin>>T;
    while(T--){
        int input; cin>>input;
        cout<<ans[input]<<"\n";
    }

}