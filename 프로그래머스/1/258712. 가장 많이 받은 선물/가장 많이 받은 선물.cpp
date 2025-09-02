#include <string>
#include <vector>
#include<map>
#include<sstream>

using namespace std;


int solution(vector<string> friends, vector<string> gifts) {
    map<string, map<string, int>> doubleMap;
    map<string, map<string, bool>> checked;
    map<string, int> giftScore;
    map<string, int> nextMonth;

    for (string s1: friends) { //init
        for (string s2: friends) {
            if (s1 != s2) {
                doubleMap[s1][s2] = 0;
                giftScore[s1] = 0;
                nextMonth[s1] = 0;
                checked[s1][s2] = false;
            }
        }
    }
    for (string s: gifts) {
        istringstream iss(s);
        string name1;
        iss >> name1;
        string name2;
        iss >> name2;
        doubleMap[name1][name2] += 1;
        giftScore[name1] += 1;
        giftScore[name2] -= 1;
    }

    for (auto e: doubleMap) {
        for (auto kv: e.second) {
            string person1 = e.first;
            string person2 = kv.first;

            // Skip if this pair has already been processed
            if (checked[person1][person2]) {
                continue;
            }

            // Mark the pair as processed to avoid double-counting
            checked[person1][person2] = true;
            checked[person2][person1] = true;

            int p1_gave_p2 = doubleMap[person1][person2];
            int p2_gave_p1 = doubleMap[person2][person1];

            // Rule 1: Compare gift counts
            if (p1_gave_p2 > p2_gave_p1) {
                nextMonth[person1]++; // person1 gets a gift
            } else if (p2_gave_p1 > p1_gave_p2) {
                nextMonth[person2]++; // person2 gets a gift
            } else {
                // Rule 2: If counts are equal, compare gift scores
                if (giftScore[person1] > giftScore[person2]) {
                    nextMonth[person1]++;
                } else if (giftScore[person2] > giftScore[person1]) {
                    nextMonth[person2]++;
                }
            }
        }
    }
    int maxCount = 0;
    for (auto e: nextMonth) {
        maxCount = max(maxCount, e.second);
    }
    return maxCount;
}
