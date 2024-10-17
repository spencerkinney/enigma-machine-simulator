// EnigmaMachine.h
#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"
#include <vector>
#include <string>

class EnigmaMachine {
public:
    EnigmaMachine();

    // Main encryption method
    std::string encrypt(const std::string& message);

    // Configuration methods
    void setRotorPositions(const std::string& positions);
    void setPlugboardConnections(const std::vector<std::pair<char, char>>& connections);

    // State information
    std::string getState() const;

private:
    std::vector<Rotor> rotors;
    Reflector reflector;
    Plugboard plugboard;

    // Helper methods
    char encryptChar(char c);
    void printState(char input, const std::vector<char>& path) const;
};

#endif