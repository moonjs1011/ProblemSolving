#include<iostream>
#include<vector>
using namespace std;
bool judge(int num){
    vector<int> v;
    while(num!=0){
        int n = num%10;
        v.push_back(n);
        num/=10;
    }
    int diff = v[0] - v[1];
    for(int i=0;i<v.size()-1;i++){
        if(diff!=(v[i]-v[i+1]))
            return false;
    }
    return true;
}
int solution(int N){
    int i=1;
    int cnt=0;
    while(i<=N){
        if(judge(i))
            cnt++;
        i++;
    }
    return cnt;
}
int main(){
    int N;
    cin>>N;
    int ans = solution(N);
    cout<<ans<<"\n";
}