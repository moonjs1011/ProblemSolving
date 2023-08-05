#include<iostream>
using namespace std;
int main(){
    long long A,B,C;
    cin>>A>>B>>C;
    if(B==C) {
        cout << -1 << "\n";
        return 0;
    }
    long long res = A/(C-B)+1;
    cout<< ((res <=0) ? -1 : res)<<"\n";
    return 0;
}

// A + B*i < C * i
// A+(B-C)i<0
// i = A/(C-B)