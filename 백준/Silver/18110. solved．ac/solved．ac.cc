#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
float solution(int n){
    if(n==0) //no opinion
        return 0;
    else{
        vector<int> v;
        for(int i=0;i<n;i++) {
            int input;
            cin >> input;
            v.push_back(input);
        }
        sort(v.begin(),v.end());
        float x = round(n* 0.15);
        float sum = 0;
        float cnt=0;
        for(int i=x;i<n-x;i++) {
            sum += v[i];
            cnt++;
        }

        float res = round(sum/cnt);
        return res;

    }
}
int main(){
    int n;
    cin>>n;
    float res = solution(n);
    cout<<res<<"\n";

}