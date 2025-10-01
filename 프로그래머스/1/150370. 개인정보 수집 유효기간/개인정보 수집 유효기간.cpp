//
// Created by Sung_1 on 2025. 10. 1..
//
#include <string>
#include <vector>
#include<map>

using namespace std;

//YYYY.MM.DD
vector<int> sliceDay(string day) {
    vector<int> slice;
    int yyyy = stoi(day.substr(0, 4));
    int mm = stoi(day.substr(5, 2));
    int dd = stoi(day.substr(8, 2));
    slice.push_back(yyyy);
    slice.push_back(mm);
    slice.push_back(dd);
    return slice;
}

map<char, int> convert(vector<string> terms) {
    map<char, int> m;
    for (string s: terms) {
        m[s[0]] = stoi(s.substr(2));
    }
    return m;
}

bool compare(vector<int> today, vector<int> day, int expire) {
    int y = day[0];
    int m = day[1];
    int d = day[2];

    // expire 개월 더하기
    m += expire;
    y += (m - 1) / 12;
    m = (m - 1) % 12 + 1;

    // 하루 빼기 (유효기간은 수집일 포함)
    d -= 1;
    if (d == 0) {
        d = 28;   // 문제 조건: 모든 달은 28일까지 있다고 가정
        m -= 1;
        if (m == 0) {
            m = 12;
            y -= 1;
        }
    }

    // 오늘(today)이 만료일보다 크면 만료
    if (today[0] > y) return false;
    if (today[0] == y && today[1] > m) return false;
    if (today[0] == y && today[1] == m && today[2] > d) return false;
    return true;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> sliceToday = sliceDay(today);
    map<char, int> termsMap = convert(terms);
    for (int i = 0; i < int(privacies.size()); i++) {
        string privacy = privacies[i];
        string day = privacy.substr(0, 10);
        vector<int> slice = sliceDay(day);
        int term = termsMap[privacy[11]];
        if (!compare(sliceToday, slice, term))
            answer.push_back(i + 1);

    }
    return answer;
}



