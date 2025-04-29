#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            string name, category;
            cin >> name >> category;
            m[category]++;
        }

        long long ans = 1;
        for (auto &e : m) {
            ans *= (e.second + 1);
        }
        ans -= 1; // 아무것도 착용하지 않는 경우 빼기

        cout << ans << "\n";
    }
}
