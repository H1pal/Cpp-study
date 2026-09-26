//
// Local debug entry point for `solve/` solutions.
//
// Add/remove the solution calls you want to exercise. The judge binary is
// purely for manual debugging — automated coverage lives under `tests/`.
//

#include <iostream>
#include <string>

#include "util/Util.h"
using namespace std;

int main() {
    // https://school.programmers.co.kr/learn/courses/30/lessons/120833
    // lv0
    // 정수 배열 numbers와 정수 num1, num2가 매개변수로 주어질 때, numbers의 num1번 째 인덱스부터 num2번째 인덱스까지 자른 정수 배열을 return
    // 입력 (매개변수)
    vector<int> num_list;
    int n;
    for (int i = 1; i <= 8; i++) {
        int num;
        cin >> num;
        num_list.push_back(num);
    }
    cin >> n;

    // 풀이
    vector<vector<int>> answer;
    for (int i = 0;i < num_list.size();i += n) {
        vector<int> sub(num_list.begin() + i, num_list.begin() + i + n);
        answer.push_back(sub);
    }
    // 출력(return)
    for (auto i : answer) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
