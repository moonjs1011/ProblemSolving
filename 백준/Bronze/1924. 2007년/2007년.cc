#include<iostream>

using namespace std;
string days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
string calender[13][32];

void solution() {
    int start = 1;
    calender[1][1] = days[start];
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 31; j++) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                if(i==1 && j==1) continue;
                if(j>31) break;
                else calender[i][j] = days[(++start) % 7];
            }
            else if(i==4 || i==6|| i==9 || i==11){
                if(j>30) break;
                else calender[i][j] = days[(++start) %7];
            }
            else if(i==2){
                if(j>28) break;
                else calender[i][j] = days[(++start) %7];
            }
        }
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    solution();
    cout<<calender[x][y]<<"\n";
}