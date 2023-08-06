#include<iostream>
#include<algorithm>
using namespace std;
struct Compare{
    bool operator()(int a,int b){
        return a>b;
    }
};
int solution(int *arr,int N,int K){
    int ans=0;
    sort(arr,arr+N,Compare());
    for(int i=0;N;i++){
        if(K==0)
            break;
        if(K/arr[i]>0){
           ans += K/arr[i];
           K = K % arr[i];
        }
    }
    return ans;
}

int main(){
    int N,K;
    cin>>N>>K;
    int *arr = new int[N];
    for(int i = 0; i < N;i++)
        cin>>arr[i];
    int ans = solution(arr,N,K);
    cout<<ans<<"\n";
}