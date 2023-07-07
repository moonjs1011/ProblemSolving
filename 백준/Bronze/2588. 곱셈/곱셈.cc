#include<iostream>
#include<string>
using namespace std;
int main(){
    int N;
    string M;
    cin>>N>>M;

    int res_1 = (M[2]-'0') *N;
    int res_2 = (M[1]-'0') * N;
    int res_3 = (M[0]-'0') * N;
    int res_4 = res_1 + res_2 *10+ res_3*100;
    cout<<res_1<<"\n";
    cout<<res_2<<"\n";
    cout<<res_3<<"\n";
    cout<<res_4<<"\n";


}