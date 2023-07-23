#include<iostream>
using namespace std;
unsigned long long fact(unsigned long long  N){
    if(N<=1)
        return 1;
    return N *fact(N-1);
}
unsigned long long sol(unsigned long long N){
    return N/(7*24*60*60);
}
int main(){
    unsigned long long N;
    cin>>N;
    unsigned long long res = fact(N);
    res =sol(res);
    cout<<res<<"\n";
}
