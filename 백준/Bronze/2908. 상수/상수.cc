#include<iostream>
#include<vector>
#include<string>
using namespace std;
int solution(string num1,string num2){
    string reverse_num1;
    string reverse_num2;
    for(int i=num1.size()-1;i>=0;i--)
        reverse_num1.push_back(num1[i]);
    for(int i=num2.size()-1;i>=0;i--)
        reverse_num2.push_back(num2[i]);
    int stoi_1 = stoi(reverse_num1);
    int stoi_2 = stoi(reverse_num2);
    return max(stoi_1,stoi_2);
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    string num1,num2;
    cin>>num1>>num2;
    cout<<solution(num1,num2);
}