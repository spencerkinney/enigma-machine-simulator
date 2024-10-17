#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor {
public:
    Rotor(const std::string& wiring, char notch, char initialPosition = 'A');

    char forward(char c) const;
    char backward(char c) const;
    void rotate();
    bool isAtNotch() const;
    void setPosition(char position);
    char getCurrentPosition() const;

private:
    std::string wiring;
    char notch;
    int position;

    static int letterToPosition(char c);
    static char positionToLetter(int pos);
};

#endif