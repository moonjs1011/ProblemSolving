#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solution(int N){
    vector<int> v;
   for(int i=N;i>=0;i--){
       string num = to_string(i);
       int sum=i;
       for(int j=0;j<num.size();j++){
           sum+=num[j]-'0';
       }
       if(sum==N)
           v.push_back(i);
   }
   if(v.empty())
        return 0;
   else{
       sort(v.begin(),v.end());
       return v.front();
   }
}
int main(){
    int N;
    cin>>N;
    int res = solution(N);
    cout<<res<<"\n";
}