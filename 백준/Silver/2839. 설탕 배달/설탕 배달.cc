#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int N;



void solution(){
    int count=0;
    while(N>=3){
        if(N%5==0){
            N-=5;
            count++;
        }
        else{
            N-=3;
            count++;
        }
    }
    if(N==0)
        cout<<count;
    else cout<<-1;
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    solution();

}