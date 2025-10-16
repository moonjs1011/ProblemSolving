//
// Created by Sung_1 on 2025. 10. 17..
//
#include<iostream>
#include<map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    map<int, string> intStrMap;
    map<string, int> strIntMap;
    for (int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        intStrMap[i] = name;
        strIntMap[name] = i;
    }
    while (M--) {
        string question;
        cin >> question;
        if (question[0] >= 'A' && question[0] <= 'Z') {// input이 이름인 경우, strIntMap 접근
            cout << strIntMap[question] << "\n";
        } else { //input이  숫자인 경우, intStrMap 접근
            int num = stoi(question);
            cout << intStrMap[num] << "\n";
        }
    }
}