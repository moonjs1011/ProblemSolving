//
// Created by Sung_1 on 2025. 10. 30..
//
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int T;
    cin>>T;
    int cnt=0;
    while(T--){
        string str;
        stack<char>s;
        cin>>str;
        for(char ch : str){
            if(!s.empty() && s.top()==ch){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
        if(s.empty()) cnt++;
    }
    cout<<cnt<<"\n";
}