#include<iostream>
#include <vector>
#include<set>
using namespace std;
vector<set<string>> container(20000);
int main(){
    int T;
    cin>>T;

    while(T--){
        string input;cin>>input;
        container[input.size()].insert(input);
    }
    for(int i=0;i<container.size();i++){
        for(set<string>::iterator it = container[i].begin();it!=container[i].end();it++){
            cout<<*it<<"\n";
        }
    }
}