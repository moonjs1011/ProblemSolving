#include <iostream>
using namespace std;
long long dp[101];
void init(){
    dp[1] = 1; dp[2]=1; dp[3]=1;
    dp[4]=2;dp[5]=2;
    for(int i=6;i<101;i++)
        dp[i] = dp[i-1] + dp[i-5];
}
int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        int input;
        cin>>input;
        cout<<dp[input]<<"\n";
    }
    
}