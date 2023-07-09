#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
 * init: input size of N, M and initialize board. (check)
 * 1st : function :copy board by size 8 X 8
 * 2dn : modify min_cnt from '1st'
 * */
vector<vector<char>> init(int N,int M){
    vector<vector<char>> board(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char input;cin>>input;
            board[i].push_back(input);
        }
    }
    return board;
}
vector<vector<char>>copy(vector<vector<char>> board,int start_x,int start_y){
    vector<vector<char>> copy_board(8);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            copy_board[i].push_back(board[i+start_x][j+start_y]);
        }
    }
    return copy_board;
}
int count_white(vector<vector<char>>board){
    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i%2==0){//even row
                if(j%2==0){ // even column
                    if(board[i][j]!='W') cnt++;
                }
                else{ // odd column
                    if(board[i][j]!='B') cnt++;
                }
            }
            else{
                if(j%2==0){ // even column
                    if(board[i][j]!='B') cnt++;
                }
                else{ // odd column
                    if(board[i][j]!='W') cnt++;
                }
            }
        }
    }
    return cnt;
}
int count_black(vector<vector<char>>board){
    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i%2==0){//even row
                if(j%2==0){ // even column
                    if(board[i][j]!='B') cnt++;
                }
                else{ // odd column
                    if(board[i][j]!='W') cnt++;
                }
            }
            else{
                if(j%2==0){ // even column
                    if(board[i][j]!='W') cnt++;
                }
                else{ // odd column
                    if(board[i][j]!='B') cnt++;
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;

    cin>>N>>M;
    int min_cnt = 2500;
    vector<vector<char>> board = init(N,M);
    for(int i=0;i<=board.size()-8;i++){
        for(int j=0;j<=board[i].size()-8;j++){

            vector<vector<char>>copy_board =copy(board,i,j);
                int cnt = count_white(copy_board);
                min_cnt = min(cnt,min_cnt);
                cnt = count_black(copy_board);
                min_cnt = min(cnt,min_cnt);
        }
        if(min_cnt==0)
            break;
    }
    cout<<min_cnt<<"\n";
}