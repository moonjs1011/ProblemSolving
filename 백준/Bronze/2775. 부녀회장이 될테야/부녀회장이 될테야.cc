#include<iostream>
using namespace std;
int arr[15][15];
int calulate(int floor,int n){
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=arr[floor-1][i];
    return sum;
}
int solution(int k,int n){
    for(int i=1;i<=n;i++)
        arr[0][i]=i;

    for(int i=1;i<=k;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=arr[i-1][j];
            arr[i][j]=sum;
        }
    }
    return arr[k][n];
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int k,n;
        cin>>k>>n;
        int res = solution(k,n);
        cout<<res<<"\n";
    }
}