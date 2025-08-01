//
// Created by Sung_1 on 2025. 8. 1..
//
#include<iostream>
#include<vector>

using namespace std;

int lcs(string str1, string str2) {
    //0으로 초기화
    vector<vector<int>> dict(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    int ans = 0;
    for (int i = 1; i < dict.size(); i++) {
        for (int j = 1; j < dict[i].size(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dict[i][j] = dict[i - 1][j - 1] + 1;
            } else {
                dict[i][j] = max(dict[i - 1][j], dict[i][j - 1]);
            }
            ans = max(dict[i][j], ans);
        }
    }
    return ans;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout<<lcs(str1, str2)<<"\n";
    return 0;
}