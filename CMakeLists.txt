cmake_minimum_required(VERSION 3.10)
project(EnigmaMachineSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(enigma_simulator
    src/main.cpp
    src/EnigmaMachine.cpp
    src/Rotor.cpp
    src/Reflector.cpp
    src/Plugboard.cpp
)

target_include_directories(enigma_simulator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)