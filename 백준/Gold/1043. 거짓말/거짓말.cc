#include<iostream>
#include<set>
#include<vector>

using namespace std;
int N, M;
set<int> know;
vector<vector<int>> party;

int main() {


    cin >> N >> M;
    int numPerson; // 정답을 알고 있는 인원 수
    int person; // 사람의 id
    cin >> numPerson;

    while (numPerson--) {
        cin >> person;
        know.insert(person);
    }

    for (int i = 0; i < M; i++) {
        cin >> numPerson;
        vector<int> v;
        while (numPerson--) {
            cin >> person;
            v.push_back(person);
        }
        party.push_back(v);
    }

    for (int k = 0; k < M; k++) {
        for (int i = 0; i < party.size(); i++) {
            bool knower_in_party = false;
            // 1. 해당 파티에 진실을 아는 사람이 있는지 확인
            for (int person_id: party[i]) {
                if (know.count(person_id)) {
                    knower_in_party = true;
                    break;
                }
            }

            // 2. 있다면, 파티의 모든 참석자를 know set에 추가
            if (knower_in_party) {
                for (int person_id: party[i]) {
                    know.insert(person_id);
                }
            }
        }
    }
    int cnt = 0;
    // 마지막으로, 각 파티에 최종적으로 진실을 아는 사람이 있는지 확인
    for (int i = 0; i < party.size(); i++) {
        bool can_lie = true;
        for (int person_id: party[i]) {
            // 최종 know set에 포함된 사람이 한 명이라도 있으면
            if (know.count(person_id)) {
                can_lie = false; // 이 파티에서는 거짓말을 할 수 없다
                break;
            }
        }

        if (can_lie) {
            cnt++; // 거짓말이 가능한 파티의 수를 센다
        }
    }

    cout << cnt << "\n";
}