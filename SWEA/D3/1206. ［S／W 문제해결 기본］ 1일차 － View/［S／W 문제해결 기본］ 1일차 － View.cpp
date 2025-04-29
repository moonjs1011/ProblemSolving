#include<iostream>
#include<vector>
#include<string>
using namespace std;
int max(int a,int b,int c,int d){
    int ans = a;
    ans = max(ans,b);
    ans = max(ans,c);
    ans = max(ans,d);
    return ans;
}
int solution(vector<int> v){
    int ans =0;
    for(int i=2;i<v.size()-2;i++){
        int max_height = max(v[i-1],v[i-2],v[i+1],v[i+2]);
        if(max_height > v[i]) continue;
        else{
            ans +=v[i]-max_height;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int test_case =1;test_case<=10;test_case++){
        int N;
        cin>>N;
        vector<int> v;
        for(int _=0;_<N;_++){
            int input;
            cin>>input;
            v.push_back(input);
        }
        cout<<"#"<<test_case<<" "<<solution(v)<<"\n";
    }
   
}
