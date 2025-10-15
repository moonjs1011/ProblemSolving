#include<iostream>
#include<map>
#include<algorithm>


using namespace std;


bool solution(string str, string pattern) {
    int pos = pattern.find('*');
    string back = pattern.substr(pos + 1);
    string front = pattern.substr(0, pos);
    if (str.size() < front.size() + back.size())
        return false;
    if (front != str.substr(0, front.size()))
        return false;

    if (back != str.substr(str.size() - back.size()))
        return false;
    return true;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    string pattern;
    cin >> pattern;
    while (N--) {
        string str;
        cin >> str;
        bool res = solution(str, pattern);
        if (res) cout << "DA" << "\n";
        else cout << "NE" << "\n";
    }
}
