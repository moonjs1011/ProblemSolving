#include <string>
#include <vector>
#include<queue>

#define INFINITY 99999999
using namespace std;

bool compare(string s1, string s2) {
    //assume len(s1) == len(s2)
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) cnt++;
    }
    if (cnt == 1) return true;
    else return false;
}

int bfs(int start_idx, string target, vector<string> words) {
    vector<int> dict(words.size(), INFINITY);
    queue<pair<string, int>> q; //{word,cost}
    q.push({words[start_idx], 1});
    while (!q.empty()) {
        string cur_word = q.front().first;
        int cur_cost = q.front().second;
        q.pop();
        if (cur_word == target)
            return cur_cost;
        for (int i = 0; i < words.size(); i++) {
            string next_word = words[i];
            int next_cost = cur_cost + 1;
            if (compare(cur_word, next_word) && dict[i] > next_cost) {
                dict[i] = next_cost;
                q.push({next_word, next_cost});
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = INFINITY;
    for (int i = 0; i < words.size(); i++) {
        if (compare(begin, words[i])) {
            int res = bfs(i, target, words);
            if (res != 0) answer = min(answer, res);
        }
    }
    if (answer >= INFINITY) answer = 0;
    return answer;
}