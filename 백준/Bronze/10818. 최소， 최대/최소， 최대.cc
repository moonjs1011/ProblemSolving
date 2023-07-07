#include<iostream>
#include<string>
using namespace std;
int main(){
   int T;
   cin>>T;
   int max_value =-1000000;
   int min_value =1000000;
   while(T--){
       int input;
       cin>>input;
       max_value= max(input,max_value);
       min_value= min(input,min_value);
   }
   cout<<min_value<<" "<<max_value;
}