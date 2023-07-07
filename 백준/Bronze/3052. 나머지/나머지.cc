#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    /* Using set.
    set<int>s;
    for(int i=0;i<10;i++){
        int input;cin>>input;
        s.insert(input%42);
    }
    cout<<s.size()<<"\n";
*/
    //Using array
    int *arr = new int[42];
    for(int i=0;i<10;i++){
        int input;cin>>input;
        arr[input%42]++;
    }
    int cnt=0;
    for(int i=0;i<42;i++){
        if(arr[i]!=0)
            cnt++;
    }
    cout<<cnt<<"\n";

}