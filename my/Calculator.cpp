//
// Created by gmlvkf282 on 2026. 9. 28..
//

#include <string>
#include <map>
#include <stack>

using namespace std;

namespace my {
    class Calculator {
    public:
        static vector<string> postfix(const string &s) {
            map<char, int> prior = {
                {'(', 0},
                {'*', 2},
                {'/', 2},
                {'+', 1},
                {'-', 1}
            };

            stack<char> oper;
            vector<string> result;

            const int len = s.length();
            result.reserve(len);

            for (int i = 0;i < len;i++) {
                switch (char ch = s[i]) {
                    case '+': case '-': case '*': case '/':
                        while (!oper.empty() && prior[oper.top()] >= prior[ch]) {
                            result.push_back(oper.top());
                            oper.pop();
                        }
                        result.push_back(ch);
                        break;

                    case '(':
                        oper.push(ch);
                        break;

                    case ')':
                        while (!oper.empty() && oper.top() != '(') {
                            result.push_back(oper.top());
                            auto& i = result.end();
                            i += ch;
                            oper.pop();
                        }
                        oper.pop();
                        break;

                    default:
                        if (result.back() >= '0' && result.back() <= '9') {
                            auto& i = result.end();
                            i += ch;
                        }
                        else return vector<string> { nullptr };
                        break;
                }
            }
            while (!oper.empty()) {
                result.push_back(oper.top());
                oper.pop();
            }
            return result;
        }
    };
}
