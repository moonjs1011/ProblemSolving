#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<map>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N;
	multiset<pair<int, int>> m;
	map<int, int>mp;
	for (int i = 0; i < N; i++) {
		int P, L;
		cin >> P >> L;
		m.insert({ L,P });
		mp.insert({ P,L });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		string order;
		cin >> order;
		if (order == "recommend") {
			cin >> order;
			int num = stoi(order);
			if (num == 1) {
				cout << prev(m.end())->second << "\n";
			}
			else if (num == -1) {
				cout << m.begin()->second << "\n";
			}
		}
		else if (order == "add") {
			cin >> order;
			int P = stoi(order);
			cin >> order;
			int L = stoi(order);
			m.insert({ L,P });
			mp.insert({ P,L });
		}
		else if (order == "solved") {
			int P;
			cin >> order;
			P = stoi(order);
			m.erase({mp[P],P});
			}
		}
	
}