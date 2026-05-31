#include "correct_domino.h"

#include <stdexcept>
#include <iostream>

void CorrectDomino::Check(std::string input) {
    for (int i = 0; i < input.size(); i++) {
        if (!std::isdigit(input[i])) {
            throw std::invalid_argument("Не цифра в костяшке " + input);
        }
    }
    if (input.length() != 2) {
        throw std::invalid_argument("Костяшка " + input + " должна состоять из двух цифр");
    }
}
