#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, int> giftScore(vector<string> friends, vector<string> gifts) {
    map<string, int> score;                // giftScore
    map<string, map<string, int>> history; // A->B 몇 개 줬는지
    map<string, int> next_month;

    for (auto &f : friends) {
        score[f] = 0;
        next_month[f] = 0;
    }

    for (auto &g : gifts) {
        istringstream iss(g);
        string a, b; iss >> a >> b;
        score[a]++; score[b]--;
        history[a][b]++;
    }

    // 친구 쌍을 한 번만 비교
    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            string a = friends[i];
            string b = friends[j];

            int ab = history[a][b];
            int ba = history[b][a];

            if (ab > ba) {
                next_month[a]++;
            } else if (ab < ba) {
                next_month[b]++;
            } else {
                if (score[a] > score[b]) next_month[a]++;
                else if (score[a] < score[b]) next_month[b]++;
                // 같으면 둘 다 없음
            }
        }
    }

    return next_month;
}

int solution(vector<string> friends, vector<string> gifts) {
    auto next_month = giftScore(friends, gifts);
    int answer = 0;
    for (auto &kv : next_month) {
        answer = max(answer, kv.second);
    }
    return answer;
}