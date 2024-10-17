// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <algorithm>
#include <cctype>

namespace Utils {
    // Convert a string to uppercase
    inline std::string toUpper(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(),
                       [](unsigned char c){ return std::toupper(c); });
        return result;
    }

    // Convert a single character to uppercase
    inline char toUpper(char c) {
        return std::toupper(static_cast<unsigned char>(c));
    }

    // Check if a character is alphabetic
    inline bool isAlpha(char c) {
        return std::isalpha(static_cast<unsigned char>(c));
    }
}

#endif