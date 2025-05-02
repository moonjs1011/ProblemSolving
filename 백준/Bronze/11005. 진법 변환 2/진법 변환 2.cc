#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<char>v(26);
    char c = 'A';
    for(int i=0;i<v.size();i++)
        v[i]=c++;
    
    unsigned long long N,B;
    cin>>N>>B;
    //5 2
    //a % b
    // 101
    unsigned long long res = N;
    vector<char>ans;
    while(res!=0){
        if(res%B>=10)
            ans.push_back(v[(res%B)-10]);
        else ans.push_back(res%B+'0');
        res = res/B;
    }
    for(int i =ans.size()-1;i>=0;i--)
        cout<<ans[i];
    cout<<"\n";
}
