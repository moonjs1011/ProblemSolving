#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    string str;cin>>str;
    int cnt=0;
    int length = str.size();
    for(int i=0;i<str.size();){
       if(str[i]=='c' && i+1 <length &&(str[i+1]=='=' || str[i+1] =='-')){
           cnt++;
           i+=2;
       }
       else if(str[i]=='d' && i+1 <length && str[i+1]=='z' && i+2 < length && str[i+2] == '=' ){
           cnt++;
           i+=3;
       }
       else if(str[i]=='d' && i+1 < length && str[i+1]=='-'){
           cnt++;
           i+=2;
       }
       else if(str[i]=='l' && i+1 <length && str[i+1]=='j') {
           cnt++;
           i+=2;
       }
       else if(str[i]=='n' && i+1 < length && str[i+1]=='j') {
           cnt++;
           i+=2;
       }
       else if((str[i]=='s' || str[i]=='z') && i+1<length && str[i+1] =='=') {
           cnt++;
           i+=2;
       }
       else {
           cnt++;
           i++;
       }
    }
    cout<<cnt<<"\n";
}