#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int sum=0;
    for(int i=0;i<5;i++) {
        int input;cin>>input;
        sum +=input*input;
    }

    cout<<sum%10;
}