#include<iostream>
#include <cmath>

using namespace std;
int main(){
    int len;
    cin>>len;
    long long sum=0;
    int r=1;
    int M = 1234567891;
    string num;
    cin>>num;
    for(int i=0;i<num.size();i++){
        sum+= (num[i]-96)* r;
        r = (r* 31) % M;
    }
    long long res = sum%M;
    cout<<res<<"\n";
}