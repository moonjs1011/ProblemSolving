#include<iostream>
#include<map>
#include<algorithm>


using namespace std;

int main() {
    string str;
    //a = 97 ,a=122 A = 65 Z = 90
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') { // 대문자일때
            cout << char((str[i] - 'A' + 13) % 26 + 'A');
        } else if ('a' <= str[i] && str[i] <= 'z') {
            cout << char((str[i] - 'a' + 13) % 26 + 'a');
        } else { //공백이거나 숫자일때, 그대로 출력
            cout << str[i];
        }
    }
}
