//
// Programmers lv0 — FindingMedian
//

#include "FindingMedian.h"
#include <iostream>
#include <vector>

namespace programmers::lv0 {
    std::vector<int> FindingMedian() {
        std::vector<int> answer;
        int cs;
        std::cin >> cs;
        answer.reserve(cs);
        for (int i = 0; i < cs; i++) {
            int temp;
            std::cin >> temp;
            answer.push_back(temp);
        }
        return answer;
    }
}
