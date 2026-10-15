//
// Created by gmlvkf282 on 2026. 9. 28..
//

#pragma once
#include <vector>
#include <string>

namespace my {
    class Calculator {
    public:
        std::vector<std::string> postfix(const std::string& s);
        int calculate(const std::string& s, const int& mode);
    };
}
