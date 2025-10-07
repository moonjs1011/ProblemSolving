#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int tall;
	int sum = 0;
	vector<int> tall_v;
	for (int i = 0; i < 9; i++) {
		cin >> tall;
		tall_v.push_back(tall);
		sum += tall;
	}
	

	sort(tall_v.begin(), tall_v.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - tall_v[i] - tall_v[j] == 100) {
				for (int k = 0; k <9; k++) {
					if (i == k || j == k)
						continue;
					cout << tall_v[k] << endl;
				}
				return 0;
			}
		}
	}

}


	
