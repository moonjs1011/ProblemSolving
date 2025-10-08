/*
5 3 1
1 6
3 5
2 8

1 A : 5
2 B : 3
3~5 C :1
6 B : 3
7~8 A : 1

1 2 3 4 5 6 7 8
0 0 0 0 0 0
    0 0 0
  0 0 0 0 0 0 0
5 + 3*2 + 1*3 + 1*3+1*3+ 3*2 + 5 + 5
 15 + 12 + 9
 27
5 + 3*2 + 1* 3 1*3



A + B + 3*C + B + 2A
 3A +2B+3C
 15+6+3

      겹치는 시간을 구한다
      구간을 Slice 한다.
      pair로 받는다.
 */
#include<iostream>
#include<vector>
#include<map>

using namespace std;
int valid[101];

int main() {
    map<int, int> m;
    int num = 1;
    while (num <= 3) {
        int input;
        cin >> input;
        m[num++] = input; //1대일때 = input && 2대일떄 = input && 3대일때 = input
    }
    num = 1;
    while (num <= 3) {
        int start, end;
        cin >> start >> end;
        for (int i = start; i < end; i++) {
            valid[i] += 1;
        }
        num++;
    }
    int sum = 0;
    for (int i = 1; i < 101; i++) {
        sum += m[valid[i]] * valid[i];
    }
    cout << sum << "\n";


}