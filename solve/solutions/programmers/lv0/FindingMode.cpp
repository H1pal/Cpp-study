//
// Created by gmlvkf282 on 26. 9. 7..
//

#include "FindingMode.h"

using namespace std;

namespace programmers::lv0 {
    int findingMode(const vector<int> array) {
        int answer = 0;
        int counter[1004] = { 0 };
        int maxCount = 0;
        for (const int i : array) {
            counter[i]++;
        }
        for (int i = 0; i < 1000; i++) {
            if (counter[i] > maxCount) {
                maxCount = counter[i];
                answer = i;
            }
            else if (counter[i] == maxCount && counter[i] != 0) {
                answer = -1; // 동점 발생
            }

        }
        return answer;
    }
}
