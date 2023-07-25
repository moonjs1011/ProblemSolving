#include<iostream>
#include<algorithm>
using namespace std;

int * init_list(int N){ // init input & return array
    int *arr = new int[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    return arr;
}

bool * init_check(int N){ // return check array
    bool *arr = new bool[N];
    for(int i=0;i<N;i++){
        arr[i]=false;
    }
    return arr;
}

int main(){
    int N,K;
    cin>>N>>K;
    int *list=init_list(N);
    bool *check = init_check(N);
    int cnt=0;
    for(int i=0;i<N;i++){
        int max_index=-1;
        for(int j=i+1;j<N;j++){
            if(!check[i] && !check[j] && list[i]+list[j]<=K){
                max_index= max(max_index,j);
            }
        }
        if(max_index!=-1){
            check[i]=check[max_index]=true;
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}