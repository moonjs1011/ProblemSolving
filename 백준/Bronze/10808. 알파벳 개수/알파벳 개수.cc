#include<iostream>

using namespace std;
int cnt[26];

int main() {
    string s;
    cin >> s;
    for (char ch: s) {
        cnt[ch - '0' - 49]++;
    }
    for (auto e: cnt)
        cout << e << " ";
}