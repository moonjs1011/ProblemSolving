import java.util.*;
/*
sol. 전수조사(완탐)
1. dungeons를 index 0~N-1까지 탐색
2. 탐색 : dfs
*/
class Solution {
    boolean[] visited = new boolean[8];
    int maxDepth=0;
    int size;
    public void dfs(int[][]dungeons, int index,int depth,int curHp){
        for(int i=0;i<size;i++){
            if(!visited[i]&&curHp>=dungeons[i][0]){
                visited[i]=true;//back-tracking
                dfs(dungeons,i,depth+1,curHp-dungeons[i][1]);
                visited[i]=false;//back-tracking
            }
        }
        maxDepth = Math.max(maxDepth,depth);
    }
    public int solution(int k, int[][] dungeons) {
        size = dungeons.length;
        dfs(dungeons,0,0,k);
        return maxDepth;
    }

}