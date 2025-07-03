#include <string>
#include <vector>
#include<cstring>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int dict[101][101];
    memset(dict,0,sizeof(dict));
    for(int i=0;i<results.size();i++){
        int win = results[i][0];
        int lose = results[i][1];
        dict[win][lose] = 1;
        dict[lose][win] = -1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dict[i][k]==1 && dict[k][j]==1){
                    dict[i][j]=1;
                    dict[j][i]=-1;
                }
                if(dict[i][k]==-1 && dict[k][j]==-1){
                    dict[i][j]=-1;
                    dict[j][i]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(dict[i][j]!=0) cnt++;
        }
        if(cnt==n-1) answer++;
    }
    return answer;
}