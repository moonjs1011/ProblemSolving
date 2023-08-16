#include<iostream>
#include<string>
#include<map>

using namespace std;
map<int, string> map_int_str;
map<string, int> map_str_int;

void find_name(int index) {
    cout << map_int_str[index] << "\n";
    return;
}

void find_index(string name) {
    cout << map_str_int[name] << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        map_int_str.insert({i, name});
        map_str_int.insert({name, i});
    }
    while (M--) {
        string input;
        cin >> input;
        if (input[0] - '0' >= 1 && input[0] - '0' <= 9) {
            find_name(stoi(input));
        } else find_index(input);
    }
}
