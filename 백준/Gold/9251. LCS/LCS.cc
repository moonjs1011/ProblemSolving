//
// Created by Sung_1 on 2025. 8. 1..
//
#include<iostream>
#include<vector>

using namespace std;

void lcs(string str1, string str2) {
    //0으로 초기화
    vector<vector<int>> dict(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for (int i = 1; i < dict.size(); i++) {
        for (int j = 1; j < dict[i].size(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dict[i][j] = dict[i - 1][j - 1] + 1;
            } else {
                dict[i][j] = max(dict[i - 1][j], dict[i][j - 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < dict.size(); i++) {
        for (int j = 0; j < dict[i].size(); j++) {
            if (ans < dict[i][j])
                ans = dict[i][j];
        }
    }
    cout << ans;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    lcs(str1, str2);
}