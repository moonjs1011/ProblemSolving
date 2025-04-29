#include<iostream>
using namespace std;
int gcd(int a ,int b){
    if(a<b)
        swap(a,b);
    if(b==0)
        return a;
    return gcd(b, a%b);
}
int lcm(int a,int b){
    return (a*b) / gcd(a,b);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int M,N,x,y;
        cin>>M>>N>>x>>y;
        int LCM = lcm(M,N);
        int ans = -1;
        for(int i=0;i<=LCM;i+=M){
            int cy = (x + i) % N;
            if(cy==0)
                cy = N;
            if(cy ==y){
                ans = i+x;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}
