//
// Programmers lv0 — AdditionOfFractions
// Two fractions are added and the result is returned in lowest terms.
//

#ifndef PROGRAMMERS_LV0_ADDITION_OF_FRACTIONS_H
#define PROGRAMMERS_LV0_ADDITION_OF_FRACTIONS_H

#include <vector>

namespace programmers::lv0 {
    // Adds numer1/denom1 + numer2/denom2 and reduces the result.
    // Returns {numerator, denominator} in lowest terms.
    std::vector<int> AdditionOfFractions(
        int numer1, int denom1,
        int numer2, int denom2
    );
}

#endif // PROGRAMMERS_LV0_ADDITION_OF_FRACTIONS_H
