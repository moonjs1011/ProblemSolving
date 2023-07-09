#include<iostream>
using namespace std;
bool solution(string input){
    string reverse;
    for(int i=input.size()-1;i>=0;i--)
        reverse.push_back(input[i]);
    return reverse==input;
}
int main(){
    string input;
    cin>>input;
    while(input!="0"){
        bool res = solution(input);
        if(res)
            cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
        cin>>input;
    }

}
