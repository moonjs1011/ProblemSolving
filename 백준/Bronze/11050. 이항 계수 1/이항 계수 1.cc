#include<iostream>
using namespace std;
int solution(int N,int M){
    if (M==0 ||N==M)
        return 1;
    if(N-M<M)
        M = N-M;//swap
    int res = N;
    int div = M;
    while(M-1>0) {
        M--;
        N--;
        res *=N;
        div *=M;
    }
    return res/div;

}
int main(){
    int N,M;
    cin>>N>>M;
    int res = solution(N,M);
    cout<<res<<"\n";
}