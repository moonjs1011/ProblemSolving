#include<iostream>
#include<vector>
using namespace std;
int main(){
  pair<int,int>max_idx = make_pair(0,0);
  for(int i=1;i<=9;i++){
    int input;
    cin>>input;
    if(input>max_idx.first){
        max_idx = make_pair(input,i);
    }
  }
  cout<<max_idx.first<<"\n"<<max_idx.second;
}