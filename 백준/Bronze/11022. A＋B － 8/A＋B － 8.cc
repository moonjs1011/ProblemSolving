#include<iostream>
#include<string>
using namespace std;
int main(){
  int T;
  cin>>T;
  int i=1;
  while(i<=T){
      int a,b;
      cin>>a>>b;
      cout<<"Case #"<<i<<": "<<a<<" + "<<b<<" = "<<a+b<<"\n";
      i++;
  }
}