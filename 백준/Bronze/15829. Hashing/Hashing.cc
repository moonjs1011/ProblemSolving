#include<iostream>
#include <cmath>

using namespace std;
int main(){
    int len;
    cin>>len;
    long long sum=0;
    long long r=1;
    long long  M = 1234567891;
    string num;
    cin>>num;
    for(int i=0;i<num.size();i++){
        sum= (sum+ (num[i]-96)* r)%M;
        r = (r* 31) % M;
    }
    cout<<sum<<"\n";
}