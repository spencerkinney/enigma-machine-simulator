// EnigmaMachine.cpp
#include "EnigmaMachine.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <sstream>

EnigmaMachine::EnigmaMachine() : reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT") {
    rotors.emplace_back("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A');
    rotors.emplace_back("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A');
    rotors.emplace_back("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A');
}

std::string EnigmaMachine::encrypt(const std::string& message) {
    std::string result;
    for (char c : message) {
        if (Utils::isAlpha(c)) {
            result += encryptChar(c);
        } else {
            result += c;
        }
    }
    return result;
}

char EnigmaMachine::encryptChar(char c) {
    c = Utils::toUpper(c);
    char original = c;
    std::vector<char> path;

    path.push_back(c);
    c = plugboard.substitute(c);
    path.push_back(c);

    // Rotate rotors
    bool rotate_next = true;
    for (auto it = rotors.rbegin(); it != rotors.rend() && rotate_next; ++it) {
        rotate_next = it->isAtNotch();
        it->rotate();
    }

    // Forward pass through rotors
    for (auto it = rotors.rbegin(); it != rotors.rend(); ++it) {
        c = it->forward(c);
        path.push_back(c);
    }

    // Reflect
    c = reflector.reflect(c);
    path.push_back(c);

    // Backward pass through rotors
    for (auto& rotor : rotors) {
        c = rotor.backward(c);
        path.push_back(c);
    }

    c = plugboard.substitute(c);
    path.push_back(c);

    printState(original, path);

    return c;
}

void EnigmaMachine::printState(char input, const std::vector<char>& path) const {
    std::cout << "\nEncryption of '" << input << "':\n";
    std::cout << "Plugboard in:  " << path[0] << " -> " << path[1] << "\n";

    for (size_t i = 0; i < rotors.size(); ++i) {
        std::cout << "Rotor " << rotors.size() - i << " (fwd): " << path[i+1] << " -> " << path[i+2] << "\n";
    }

    std::cout << "Reflector:     " << path[rotors.size()+1] << " -> " << path[rotors.size()+2] << "\n";

    for (size_t i = 0; i < rotors.size(); ++i) {
        std::cout << "Rotor " << i+1 << " (bwd): " << path[rotors.size()+2+i] << " -> " << path[rotors.size()+3+i] << "\n";
    }

    std::cout << "Plugboard out: " << path[path.size()-2] << " -> " << path[path.size()-1] << "\n";

    std::cout << "Rotor positions: ";
    for (const auto& rotor : rotors) {
        std::cout << rotor.getCurrentPosition() << " ";
    }
    std::cout << "\n";
}

void EnigmaMachine::setRotorPositions(const std::string& positions) {
    if (positions.length() != rotors.size()) {
        throw std::invalid_argument("Number of positions must match number of rotors");
    }
    for (size_t i = 0; i < rotors.size(); ++i) {
        rotors[i].setPosition(positions[i]);
    }
}

void EnigmaMachine::setPlugboardConnections(const std::vector<std::pair<char, char>>& connections) {
    for (const auto& pair : connections) {
        plugboard.connect(pair.first, pair.second);
    }
}

std::string EnigmaMachine::getState() const {
    std::ostringstream oss;
    oss << "Enigma Machine State:\n";
    oss << "Rotor positions: ";
    for (const auto& rotor : rotors) {
        oss << rotor.getCurrentPosition() << " ";
    }
    oss << "\nPlugboard connections: " << plugboard.getConnections();
    return oss.str();
}