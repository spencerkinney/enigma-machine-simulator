// Reflector.h
#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>

class Reflector {
public:
    explicit Reflector(const std::string& wiring);
    char reflect(char c) const;

private:
    std::string wiring;
};

#endif