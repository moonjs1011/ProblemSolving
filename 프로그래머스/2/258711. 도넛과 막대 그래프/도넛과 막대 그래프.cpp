#include <string>
#include <vector>
#include<cmath>
using namespace std;
int findMaxVid(vector<vector<int>>edges){
    int maxVid = 1;
    for(int i=0;i<edges.size();i++){
        int out = edges[i][0];
        int in = edges[i][1];
        maxVid = max(out,max(maxVid,in));
    }
    return maxVid;
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    int maxVid = findMaxVid(edges);
    
    vector<int> out_cnt(maxVid+1,0);    
    vector<int> in_cnt(maxVid+1,0);
    
    for(int i=0;i<edges.size();i++){
        int out = edges[i][0];
        int in = edges[i][1];
        out_cnt[out]+=1;
        in_cnt[in]+=1;        
    }
    for(int vid=1;vid<=maxVid;vid++){
        if(in_cnt[vid]>=1 && out_cnt[vid]==0) //막대 그래프
            answer[2]+=1;
        else if(in_cnt[vid]>=2 && out_cnt[vid]==2) // 8자 그래프
            answer[3]+=1;
        else if(in_cnt[vid]==0 && out_cnt[vid]>=2) // 생성된 정점 
            answer[0] = vid; 
    }
    answer[1] = out_cnt[answer[0]] - (answer[2]+answer[3]);
    return answer;
}