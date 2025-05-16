#include<iostream>
using namespace std;
int dict[101][101];
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>dict[i][j];
        }
    }
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                if(dict[i][k]&&dict[k][j])
                    dict[i][j] = 1;
            }
    for(int i=0;i<N;i++) {
        for (int j = 0; j < N; j++)
            cout << dict[i][j] << " ";
        cout << "\n";
    }
}