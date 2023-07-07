#include<iostream>
#include<vector>
using namespace std;
float max(int ele1,int ele2){
    if(ele1<ele2)
        return ele2;
    else return ele1;
}
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;cin>>N;
    double  *arr = new double[N];
    double max_value=0;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        max_value=max(max_value,arr[i]);
    }
    double sum=0;
    for(int i=0;i<N;i++){
        sum+=arr[i]/max_value*100;
    }
    cout.precision(10);
    cout<<sum/N;
}