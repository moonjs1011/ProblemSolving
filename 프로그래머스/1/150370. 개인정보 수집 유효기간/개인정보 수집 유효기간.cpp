
#include <string>
#include <vector>
#include<map>

using namespace std;

//YYYY.MM.DD
/*
날짜를 입력으로 받아 크기가 3인 vector로 변환하는 함수입니다.
ex) input : string day = "2022.03.21"
    output : vector<int> slice = {2022,3,21}
*/
vector<int> sliceDay(string day) {
    vector<int> slice;
    //yyyy.mm.dd
    int yyyy = stoi(day.substr(0, 4));
    int mm = stoi(day.substr(5, 2));
    int dd = stoi(day.substr(8, 2));
    slice.push_back(yyyy);
    slice.push_back(mm);
    slice.push_back(dd);
    return slice;
}
/*
map 자료형으로 변환하는 함수입니다.
ex) m['A'] = 4, m['B'] = 12, m['D'] = 6
*/
map<char, int> convert(vector<string> terms) {
    map<char, int> m;
    for (string s: terms) {
        m[s[0]] = stoi(s.substr(2));
    }
    return m;
}
/*
* 날짜를 비교하는 함수입니다. 유효하다면 True, 유효기간이 지났다면 False를 리턴합니다.
*/
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



