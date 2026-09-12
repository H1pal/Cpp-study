//
// Common math helpers used across solutions.
//

#ifndef SOLVE_UTIL_H
#define SOLVE_UTIL_H

#include <vector>

namespace util {
    int gcd(int dividend, int divisor);
    int lcm(int n1, int n2);
    std::vector<int> make_irreducible(const std::vector<int> &arr);
    void doubleArray(std::vector<int> &arr);
}

#endif // SOLVE_UTIL_H
