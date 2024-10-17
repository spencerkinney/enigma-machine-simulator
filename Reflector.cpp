// Reflector.cpp
#include "Reflector.h"
#include "Utils.h"
#include <stdexcept>

Reflector::Reflector(const std::string& wiring) : wiring(Utils::toUpper(wiring)) {
    if (wiring.length() != 26) {
        throw std::invalid_argument("Reflector wiring must contain exactly 26 characters");
    }
}

char Reflector::reflect(char c) const {
    return wiring[Utils::toUpper(c) - 'A'];
}