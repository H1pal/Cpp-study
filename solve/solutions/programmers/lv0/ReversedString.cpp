//
// Programmers lv0 — ReversedString
// Return the reversed version of the given string.
//

#include "ReversedString.h"
#include <algorithm>

namespace programmers::lv0 {
    std::string ReversedString(std::string my_string) {
        std::reverse(my_string.begin(), my_string.end());
        return my_string;
    }
}
