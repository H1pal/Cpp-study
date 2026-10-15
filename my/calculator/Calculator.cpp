//
// Created by gmlvkf282 on 2026. 9. 28..
//

#include "Calculator.h"

#include <map>
#include <stack>
#include <stdexcept>

using namespace std;

namespace my {


    vector<string> Calculator::postfix(const string& s) {
        const int len = s.length();
        if (len == 0) throw invalid_argument("None expression");

        /* oper에 있는 연산자들의 우선순위를 나타낸 map */
        // 해당 우선순위를 바탕으로 result에 나타낼 postfix 결과값에 반영
        map<char, int> prior = {
            {'(', 0},
            {'*', 2},
            {'/', 2},
            {'+', 1},
            {'-', 1}
        };

        stack<char> oper; // 연산자를 담을 stack
        vector<string> result; // postfix 결과값을 반환할 결과값을 담은 동적 배열
        // 두 자릿수 이상의 숫자형을 포함할 수 있으므로 vector<string>을 반환

        int openBrackets = 0; // 열린 괄호의 개수 (괄호의 유효성을 검증하기 위함)
        char prev = 0; // s[i-1]

        for (int i = 0;i < len;i++) {
            const char& ch = s[i]; // 메모리 최적화: 역참조&상수
            if (isspace(static_cast<unsigned char>(ch))) continue; // 공백은 처리하지 않음,

            switch (ch) {
                case '+': case '-': case '*': case '/':
                    if (i == 0 || i == len-1) throw invalid_argument("Expression must start or end with number");
                    if (prev == '+' || prev == '-' || prev == '*' || prev == '/') throw invalid_argument("Wrong operator sequence");
                    while (!oper.empty() && prior[oper.top()] >= prior[ch]) {
                        result.emplace_back(1, oper.top());
                        oper.pop();
                    }
                    oper.push(ch);
                    break;

                case '(':
                    openBrackets++;
                    oper.push(ch);
                    break;

                case ')':
                    if (openBrackets-- == 0) throw invalid_argument("Unmatched closing parenthesis");
                    while (!oper.empty() && oper.top() != '(') {
                        result.emplace_back(1, oper.top());
                        oper.pop();
                    }
                    oper.pop();
                    break;
                default:
                    if (isdigit(static_cast<unsigned char>(ch))) {
                        string num;
                        int start = i;
                        bool isZeroOfFirst = false;
                        num += ch;
                        while (i+1 < len && isdigit(static_cast<unsigned char>(s[i+1]))) {
                            if (!isZeroOfFirst) ++start;
                            if (s[i+1] != '0') isZeroOfFirst = true;
                            ++i;
                        }
                        result.push_back(s.substr(start, i-start+1));
                        break;
                    }
                    throw invalid_argument("Unsupported character in expression");
            }
            prev = ch;
        }
        if (openBrackets > 0) throw invalid_argument("Unmatched opening brackets");
        while (!oper.empty()) {
            result.emplace_back(1, oper.top());
            oper.pop();
        }
        return result;
    }

    int Calculator::calculate(const string& s, const int& mode) {
        const vector<string> postfix_result = postfix(s);

        stack<int> stk;
        for (const string& ch : postfix_result) {

            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                const int n2 = stk.top();
                stk.pop();
                const int n1 = stk.top();
                stk.pop();

                if (ch == "+") stk.push(n1 + n2);
                else if (ch == "-") stk.push(n1 - n2);
                else if (ch == "*") stk.push(n1 * n2);
                else if (ch == "/") stk.push(n1 / n2);
            }
            else stk.push(stoi(ch));
        }
        return stk.top();
    }
}
