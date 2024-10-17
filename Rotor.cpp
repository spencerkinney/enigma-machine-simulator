// Rotor.cpp
#include "Rotor.h"
#include "Utils.h"
#include <stdexcept>

Rotor::Rotor(const std::string& wiring, char notch, char initialPosition)
    : wiring(Utils::toUpper(wiring)), notch(Utils::toUpper(notch)), position(0) {
    if (wiring.length() != 26) {
        throw std::invalid_argument("Rotor wiring must contain exactly 26 characters");
    }
    setPosition(initialPosition);
}

char Rotor::forward(char c) const {
    int inputPos = (letterToPosition(c) + position) % 26;
    return positionToLetter((wiring[inputPos] - 'A' - position + 26) % 26);
}

char Rotor::backward(char c) const {
    int inputPos = (letterToPosition(c) + position) % 26;
    int outputPos = wiring.find(positionToLetter(inputPos));
    return positionToLetter((outputPos - position + 26) % 26);
}

void Rotor::rotate() {
    position = (position + 1) % 26;
}

bool Rotor::isAtNotch() const {
    return positionToLetter(position) == notch;
}

void Rotor::setPosition(char pos) {
    position = letterToPosition(pos);
}

char Rotor::getCurrentPosition() const {
    return positionToLetter(position);
}

int Rotor::letterToPosition(char c) {
    return Utils::toUpper(c) - 'A';
}

char Rotor::positionToLetter(int pos) {
    return static_cast<char>((pos % 26) + 'A');
}