#include<iostream>

using namespace std;
int matrix[128][128];
int N;
int cnt[2]; //cnt[0] = count of white, cnt[1] = count of blue
void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}
pair<bool,int> judge(int y,int x,int size){
    pair<bool,int> res_value;
    int value = matrix[y][x];
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(value!=matrix[i][j]){
                res_value = {false,value};
                return res_value;
            }
        }
    }
    res_value = {true,value};
    return res_value;
}
void recursive(int y,int x,int size){
    pair<bool,int> res_value = judge(y,x,size);
    bool res = res_value.first;
    int value = res_value.second;
    if(!res){ // if current region satisfies the condition.
        recursive(y,x,size/2);
        recursive(y,x+size/2,size/2);
        recursive(y+size/2,x,size/2);
        recursive(y+size/2,x+size/2,size/2);
    }
    else{
        cnt[value]++;
    }
}
int main() {
    input();
    recursive(0,0,N);
    cout<<cnt[0]<<"\n"<<cnt[1]<<"\n";
}