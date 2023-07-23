#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long solution(vector<unsigned int>v, int N,int max_val){
    unsigned int left = 1;
    unsigned int right = max_val;
    unsigned int ans=0;
    unsigned int middle;
    
    while(left<=right){
            middle= (left+right)/2;
            unsigned int div_sum = 0;
            for(int i=0;i<v.size();i++)
                div_sum+= v[i]/middle;
            if(div_sum>=N) {
                left = middle + 1;
                ans = max(ans,middle);
            }
            else right=middle-1;
    }
    return ans;
}
int main(){
    int K,N;
    vector<unsigned int> v;
    cin>>K>>N;
    unsigned int max_val=0;
    while(K--){
        unsigned int input;
        cin>>input;
        v.push_back(input);
        max_val = max(max_val,input);
    }
    unsigned int res= solution(v,N,max_val);
    cout<<res<<"\n";
}