#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, vector<string>> m; // 티켓 정보 (그래프)
vector<string> ans;           // 최종 경로
int totalTickets;             // 전체 티켓 수
bool foundPath = false;       // 정답 경로를 찾았는지 여부

/**
 * @brief 깊이 우선 탐색 (DFS)으로 여행 경로를 찾습니다.
 * @param name 현재 공항 이름
 */
void Dfs(string name) {
    // 1. 이미 모든 티켓을 사용한 경로를 찾았다면, 다른 경로는 더 탐색할 필요가 없습니다.
    if (foundPath) return;

    // 2. Base Case: 모든 티켓을 사용한 경우 (경로 길이 = 티켓 수 + 1)
    if (ans.size() == totalTickets + 1) {
        foundPath = true; // 정답을 찾았다고 표시
        return;
    }

    // 3. 현재 공항에서 출발하는 티켓이 없으면 이 경로는 실패
    if (m.find(name) == m.end()) {
        return;
    }

    // 4. 재귀 단계: 현재 공항에서 갈 수 있는 목적지들을 탐색합니다.
    // (중요) 인덱스 기반 루프를 사용해야 erase/insert가 용이합니다.
    for (int i = 0; i < m[name].size(); ++i) {
        string dst = m[name][i]; // 목적지

        // 4-1. 티켓 사용 (그래프에서 간선 제거)
        m[name].erase(m[name].begin() + i);
        ans.push_back(dst); // 경로에 추가

        // 4-2. 다음 목적지로 Dfs 재귀 호출
        Dfs(dst);

        // 4-3. (중요) Dfs(dst)가 성공적으로 경로를 찾았다면, 즉시 리턴
        if (foundPath) return;

        // 4-4. 백트래킹 (Backtracking)
        // -> Dfs(dst)가 실패한 경로였다면, 사용했던 티켓을 복원하고 경로에서 제거
        ans.pop_back();
        m[name].insert(m[name].begin() + i, dst);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // 0. (중요) 전역 변수 초기화 (테스트 케이스가 여러 개일 수 있음)
    m.clear();
    ans.clear();
    foundPath = false;
    totalTickets = tickets.size();

    // 1. 그래프(map) 생성
    for (vector<string> ticket : tickets) {
        string src = ticket[0];
        string dst = ticket[1];
        m[src].push_back(dst);
    }

    // 2. (버그 수정) map의 value(vector)를 정렬 (참조자 & 사용)
    for (auto& pair : m) {
        sort(pair.second.begin(), pair.second.end());
    }

    // 3. DFS 시작
    ans.push_back("ICN"); // 시작점은 항상 "ICN"
    Dfs("ICN");

    return ans;
}