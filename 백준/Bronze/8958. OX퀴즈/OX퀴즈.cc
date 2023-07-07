#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        string quiz;
        cin >> quiz;
        int total_score = 0;
        int cnt = 0;
        for (int i = 0; i < quiz.size(); i++) {
            if (quiz[i] == 'O') {
                cnt++;
            } else cnt = 0;
            total_score += cnt;
        }
        cout << total_score<<"\n";
    }
}