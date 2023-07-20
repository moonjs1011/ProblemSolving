#include <iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,int> m;

void insert(int input){
    if(m.find(input)==m.end()){
        m.insert({input,1});
    }
    else{
        m[input] = m[input]+1;
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    while(N--){
        int input;
        cin>>input;
        insert(input);
    }
    int M;
    cin>>M;
    while(M--){
        int input; cin>>input;
        cout<<m[input]<<" ";
    }
}


