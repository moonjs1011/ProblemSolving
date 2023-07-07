#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    set<int>s;
    for(int i=0;i<10;i++){
        int input;cin>>input;
        s.insert(input%42);
    }
    cout<<s.size()<<"\n";

}