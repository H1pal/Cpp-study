//
// Programmers lv0 — RemovingSpecificChar
// Remove all occurrences of a given character from a string.
//

#include "RemovingSpecificChar.h"

namespace programmers::lv0 {
    std::string RemovingSpecificChar(std::string my_string, std::string letter) {
        std::string answer = "";
        for (const char i : my_string) {
            if (letter[0] != i) {
                answer += i;
            }
        }
        return answer;
    }
}
