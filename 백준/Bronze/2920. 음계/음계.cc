#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int *arr = new int[8];
    for(int i=0;i<8;i++){
        cin>>arr[i];
    }
    int weight=0;
    for(int i=0;i<7;i++){
        if(arr[i]<arr[i+1])
            weight++;
        else weight--;
    }
    if(weight==7)
        cout<<"ascending";
    else if(weight==-7)
        cout<<"descending";
    else cout<<"mixed";
}