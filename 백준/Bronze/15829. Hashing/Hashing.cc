#include<iostream>
#include <cmath>

using namespace std;
int main(){
    int len;
    cin>>len;
    long long sum=0;
    long long r = 31;
    for(int i=0;i<len;i++) {
        char ch;
        cin >> ch;
        long long num = ch - 96;
        sum+= num * pow(31,i);
    }
    cout<<sum<<"\n";
}