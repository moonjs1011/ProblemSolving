#include<iostream>
using namespace std;
#define MAX_SIZE 1000001
long long arr[MAX_SIZE];
void solution(int M,int N){

    for(long long i=2;i<=N;i++)
        arr[i]=i;
    for(long long i=2;i<=N;i++){
        if(arr[i]==0)
            continue;
        for(long long j=i*i;j<=N;j+=i){
            arr[j]=0;
        }
    }
    for(long long i=M;i<=N;i++){
        if(arr[i]!=0)
            cout<<i<<"\n";
    }
}
int main(){
    int M,N;
    cin>>M>>N;
    solution(M,N);
}