//
// Common math helpers used across solutions.
//

#include "Util.h"
#include <vector>

namespace util {
    /** 최대공약수: 유클리드 호제법을 이용하여 두 수의 최대공약수 계산
     *
     * @param dividend {int} - 숫자 1
     * @param divisor {int} - 숫자 2
     * @return 두 수의 최대공약수를 반환
     */
    int gcd(const int dividend, const int divisor) {
        if (dividend > divisor) return divisor == 0 ? dividend : gcd(divisor, dividend % divisor);
        return dividend == 0 ? divisor : gcd(dividend, divisor % dividend);
    }

    /** 최소공배수: gcd(최대공약수) 함수를 이용하여 두 수의 최소공배수 계산
     *
     * @param n1 {int} - 숫자 1
     * @param n2 {int} -  숫자 2
     * @return {int} - 두 수의 최소공배수를 반환
     */
    int lcm(const int n1, const int n2) { return (n1 * n2) / gcd(n1, n2); }

    /** 분모와 분자 각각 하나씩 받아 기약분수로 나타냄 **ref**
     *
     * @param {std::vector<int>} &arr - 약분하려는 분자와 분모가 각각 하나씩 담긴 배열
     * @return {std::vector<int>} 기약 분수로 나타낸 분자와 분모가 각각 하나씩 담긴 배열을 반환
     */
    std::vector<int> make_irreducible(const std::vector<int> &arr) {
        const int g = gcd(arr[0], arr[1]);
        return std::vector<int> { arr[0] / g, arr[1] / g };
    }

    /** 동적 배열을 참조하여 각 원소에 2를 곱함 **ref**
     *
     * @param {std::vector<int>} &arr - 정수형 요소가 담겨 있는 배열
     * @exam doubleArray(vector<int> { 1, 2, 3, 4 }
     */
    void doubleArray(std::vector<int> &arr) {
        for (int & i : arr) {
            i *= 2;
        }
    }
}
