#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    priority_queue<int> pq;
    while(N--){
       int x;
       cin>>x;
       if(x==0){
           if(!pq.empty()) {
               int top = pq.top();
               pq.pop();
               cout << top << "\n";
           }
           else cout<<0<<"\n";
       }
       else{
           pq.push(x);
       }
    }
}