//
// Created by gmlvkf282 on 26. 10. 15..
//

#include <iostream>
#include "calculator/Calculator.h"

int main() {
    const auto calculator = new my::Calculator();
    const auto postfix_result = calculator->postfix("1*5-3");
    for (const auto& c: postfix_result) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::cout << calculator->calculate("00100*02+3+1*2", 0) << std::endl;

    return 0;
}