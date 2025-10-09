#include<iostream>
#include<map>
#include<algorithm>


using namespace std;

int main() {
    map<char, int> m;
    int N;
    cin >> N;
    while (N--) {
        string firstName;
        cin >> firstName;
        if (m.find(firstName[0]) == m.end())//없을 경우
            m[firstName[0]] = 0;
        m[firstName[0]] += 1;

    }
    bool flag = false;
    for (auto e: m) {
        char firstLetter = e.first;
        int cnt = e.second;
        if (cnt >= 5) {
            flag = true;
            cout << firstLetter;
        }
    }
    if (!flag) {
        cout << "PREDAJA" << "\n";
    }
}