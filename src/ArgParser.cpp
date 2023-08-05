//
// Created by spcie on 8/2/2023.
//

#include "ArgParser.h"

ArgParser::ArgParser() {
    manual = "";
}

void ArgParser::ReadManual(std::string fn) {
    // Reads manual.txt
    std::ifstream inFS(fn);

    if (inFS) {   // If file is open
        std::stringstream buffer;
        buffer << inFS.rdbuf();
        manual = buffer.str();
    }
    else {
        std::cout << "Could not open file :(" << std::endl;
        exit(1);
    }
}

std::string ArgParser::GetManual() {
    return manual;
}