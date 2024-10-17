// Plugboard.cpp
#include "Plugboard.h"
#include "Utils.h"
#include <sstream>

void Plugboard::connect(char a, char b) {
    a = Utils::toUpper(a);
    b = Utils::toUpper(b);
    connections[a] = b;
    connections[b] = a;
}

char Plugboard::substitute(char c) const {
    c = Utils::toUpper(c);
    auto it = connections.find(c);
    return (it != connections.end()) ? it->second : c;
}

std::string Plugboard::getConnections() const {
    std::ostringstream oss;
    for (const auto& pair : connections) {
        if (pair.first < pair.second) {  // To avoid duplicates
            oss << pair.first << pair.second << " ";
        }
    }
    return oss.str();
}