#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solution(vector<int> v){
    int min_value = 1e10;
    sort(v.begin(),v.end());
    int cur_time = 0;
    int sum_time = 0;

    for(int i=0;i<v.size();i++){
        cur_time += v[i];
        sum_time += cur_time;
    }
    cout<<sum_time<<"\n";
}
int main(){
    int T; cin>>T;

    vector<int>v;

    while(T--){
        int input; cin>>input;
        v.push_back(input);
    }
    solution(v);

}