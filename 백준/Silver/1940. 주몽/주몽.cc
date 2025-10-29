//
// Created by Sung_1 on 2025. 10. 29..
//

#include<iostream>
#include<algorithm>
using namespace std;
/*
 * N = target 그냥 두번만 하면 되는데 조합을 이용합시다.
 */
vector<int> v;
int N,M,cnt;
void combination(vector<int>&num,vector<int>&v,int r,int depth){
    if(num.size()==r){
        int sum =0;
        for(auto e : num){
            sum+=e;
        }
        if(sum==M) cnt++;
    }
    else{
        for(int i = depth;i<v.size();i++){
            num.push_back(v[i]);
            combination(num,v,r,i+1);
            num.pop_back();
        }
    }
}
int main(){

    cin>>N>>M;
    while(N--){
        int input;cin>>input;
        v.push_back(input);
    }
    vector<int>num;
    combination(num,v,2,0);


    cout<<cnt<<"\n";
}