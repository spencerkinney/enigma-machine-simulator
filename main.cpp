#include "EnigmaMachine.h"
#include <iostream>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "\nEnigma Machine Simulator\n";
    std::cout << "1. Encrypt a message\n";
    std::cout << "2. Set rotor positions\n";
    std::cout << "3. Set plugboard connections\n";
    std::cout << "4. Show current machine state\n";
    std::cout << "5. Quit\n";
    std::cout << "Enter your choice: ";
}

std::string getInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

int main() {
    EnigmaMachine enigma;
    std::string input;

    while (true) {
        printMenu();
        std::getline(std::cin, input);

        if (input == "1") {
            std::string message = getInput("Enter a message to encrypt: ");
            std::cout << "Encrypted message: " << enigma.encrypt(message) << "\n";
        }
        else if (input == "2") {
            std::string positions = getInput("Enter rotor positions (e.g., ABC for 3 rotors): ");
            try {
                enigma.setRotorPositions(positions);
                std::cout << "Rotor positions set successfully.\n";
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
        else if (input == "3") {
            std::vector<std::pair<char, char>> connections;
            while (true) {
                std::string pair = getInput("Enter a plugboard connection (e.g., AB) or press Enter to finish: ");
                if (pair.empty()) break;
                if (pair.length() == 2) {
                    connections.emplace_back(pair[0], pair[1]);
                } else {
                    std::cout << "Invalid input. Please enter exactly two letters.\n";
                }
            }
            enigma.setPlugboardConnections(connections);
            std::cout << "Plugboard connections set successfully.\n";
        }
        else if (input == "4") {
            std::cout << enigma.getState() << "\n";
        }
        else if (input == "5") {
            std::cout << "Thank you for using the Enigma Machine Simulator. Goodbye!\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}