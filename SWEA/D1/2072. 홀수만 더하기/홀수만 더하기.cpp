#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    for(int test_case =1;test_case<=T;test_case++){
        int sum =0;
        int i =10;
        while(i--){
            int input;
            cin>>input;
            if(input%2 == 1) sum+=input;
        }
        cout<<"#"<<test_case<<" "<<sum<<"\n";
    }
   
}
