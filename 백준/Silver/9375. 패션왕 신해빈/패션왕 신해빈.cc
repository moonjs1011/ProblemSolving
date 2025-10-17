//
// Created by Sung_1 on 2025. 10. 17..
//
#include<iostream>
#include<map>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<string, int> m;
        while (n--) {
            string name, category;
            cin >> name >> category;
            m[category] += 1;
        }
        int res = 1;
        for (auto &e: m) {
            res *= e.second + 1;
        }
        cout << res - 1 << "\n";
    }
}