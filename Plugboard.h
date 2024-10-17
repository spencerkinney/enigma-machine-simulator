// Plugboard.h
#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <unordered_map>
#include <string>

class Plugboard {
public:
    void connect(char a, char b);
    char substitute(char c) const;
    std::string getConnections() const;

private:
    std::unordered_map<char, char> connections;
};

#endif