#include<iostream>
#include<stack>

using namespace std;

int compute(string str) {
    bool is_Minus = false;
    int total = 0;
    string num = "";
    for (int i = 0; i <= str.size(); i++) {
        if(str[i]=='+' || str[i] == '-' || i==str.size()){
            if(is_Minus){
                total -= stoi(num);
                num="";
            }
            else{
                total +=stoi(num);
                num="";
            }
        }
        else{
            num +=str[i];
        }
        if(str[i]=='-') is_Minus=true;
    }
    return total;
}

int main() {
    string str;
    cin >> str;
    int res = compute(str);
    cout << res << "\n";
}