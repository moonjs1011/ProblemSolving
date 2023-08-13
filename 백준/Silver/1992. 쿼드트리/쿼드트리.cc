#include <iostream>
#include <vector>

using namespace std;
char matrix[64][64];
int N;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            cin>>matrix[i][j];
        }

}

pair<bool, char> judge(int y, int x, int size) {
    char value = matrix[y][x];
    pair<bool,char> res_val;
    for (int i = y; i < y+size; i++) {
        for (int j = x; j < x+size; j++) {
            if (value != matrix[i][j]) {
                res_val = {false, value};
                return res_val;
            }
        }
    }
    res_val = {true, value};
    return res_val;
}

void recursive(int y, int x, int size) {
    pair<bool, char> res_val = judge(y, x, size);
    if (res_val.first == true) {
        cout << res_val.second;
        return;
    }
    else {
        cout << "(";
        recursive(y, x, size / 2);
        recursive(y, x + size / 2, size / 2);
        recursive(y + size / 2, x, size / 2);
        recursive(y + size / 2, x + size / 2, size / 2);
        cout << ")";
    }
}


int main() {

    input();
    recursive(0, 0, N);
}
