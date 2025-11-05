#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

// 1. 전역 변수 선언 (테스트 케이스마다 초기화 필요)
map<string, vector<string>> m; // key: 출발, value: 도착지 목록
vector<string> ans;          // 최종 경로

// DFS (오일러 경로 탐색 방식)
void Dfs(string airport) {
    // 2. 현재 공항에서 출발하는 티켓이 남아있는 동안 반복
    // (for-loop 대신 while을 쓰는 이유: 반복 도중 m[airport]의 요소를 삭제할 것이기 때문)
    while (!m[airport].empty()) {
        
        // 3. 알파벳 순으로 정렬했으므로, 항상 0번째가 다음 목적지
        string next_dst = m[airport][0];
        
        // 4. "티켓 사용" : 0번째 티켓을 맵에서 삭제
        m[airport].erase(m[airport].begin());
        
        // 5. 다음 목적지로 DFS 수행
        Dfs(next_dst);
    }
    
    // 6. 현재 공항에서 더 이상 갈 곳이 없을 때 (막다른 길일 때)
    //    ans에 경로를 추가합니다. (경로가 역순으로 쌓임)
    ans.push_back(airport);
}

vector<string> solution(vector<vector<string>> tickets) {
    
    // --- [필수] 전역 변수 초기화 ---
    // 프로그래머스에서는 solution 함수가 여러 번 호출되므로,
    // 전역 변수를 매번 깨끗하게 비워줘야 합니다.
    m.clear();
    ans.clear();

    // 1. 그래프(맵) 생성
    for (vector<string> ticket : tickets) {
        string src = ticket[0];
        string dst = ticket[1];
        m[src].push_back(dst);
    }
    
    // 2. 모든 목적지 리스트를 알파벳 순으로 정렬
    // (참조(&)를 사용해야 원본이 정렬됨)
    for (auto &e : m) {
        sort(e.second.begin(), e.second.end());
    }

    // 3. "ICN"에서 DFS 시작
    Dfs("ICN");
    
    // 4. ans에는 경로가 역순으로 쌓여있으므로 (e.g., IAD -> HND -> JFK -> ICN)
    //    뒤집어서 올바른 순서로 만듭니다.
    reverse(ans.begin(), ans.end());
    
    return ans;
}