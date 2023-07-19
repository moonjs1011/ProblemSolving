#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    int *num_arr = new int[10];
    num_arr[0]= 11;
    for(int i=1;i<10;i++)
        num_arr[i]=i+1;
    unordered_map<char,int> m;
    m.insert({'A',3});
    m.insert({'B',3});
    m.insert({'C',3});
    m.insert({'D',4});
    m.insert({'E',4});
    m.insert({'F',4});
    m.insert({'G',5});
    m.insert({'H',5});
    m.insert({'I',5});
    m.insert({'J',6});
    m.insert({'K',6});
    m.insert({'L',6});
    m.insert({'M',7});
    m.insert({'N',7});
    m.insert({'O',7});
    m.insert({'P',8});
    m.insert({'Q',8});
    m.insert({'R',8});
    m.insert({'S',8});
    m.insert({'T',9});
    m.insert({'U',9});
    m.insert({'V',9});
    m.insert({'W',10});
    m.insert({'X',10});
    m.insert({'Y',10});
    m.insert({'Z',10});

    string input; cin>>input;
    int cnt=0;
    for(int i=0;i<input.length();i++){
        cnt+=m.find(input[i])->second;
    }
    cout<<cnt<<"\n";
}