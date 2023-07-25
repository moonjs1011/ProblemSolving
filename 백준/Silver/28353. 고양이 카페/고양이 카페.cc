#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    vector<int> v;
    vector<bool>check;
    for(int i=0;i<N;i++){
        int input;
        cin>>input;
        v.push_back(input);
        check.push_back(false);
    }
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=0;i<N;i++){
        int max_j=-1;
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(!check[i] && !check[j] &&(v[i]+v[j])<=K){
                max_j = max(j,max_j);
            }
        }
        if(max_j!=-1){
            check[i]=true;
            check[max_j]=true;
            cnt++;

        }
    }
    cout<<cnt<<"\n";
}