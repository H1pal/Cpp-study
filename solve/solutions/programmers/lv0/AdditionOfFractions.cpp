//
// Programmers lv0 — AdditionOfFractions
//

#include "AdditionOfFractions.h"
#include "../../../util/Util.h"
#include <vector>

namespace programmers::lv0 {
    std::vector<int> AdditionOfFractions(
        const int numer1, const int denom1,
        const int numer2, const int denom2
    ) {
        const int commonDenom = util::lcm(denom1, denom2);
        const int numerResult = numer1 * (commonDenom / denom1)
                              + numer2 * (commonDenom / denom2);

        return util::make_irreducible({numerResult, commonDenom});
    }
}
