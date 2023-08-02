//
// Created by spcie on 8/2/2023.
//

#ifndef PROJECT_3_EMOJI_ARGPARSER_H
#define PROJECT_3_EMOJI_ARGPARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ArgParser {
    private:
        std::string manual;
    public:
        ArgParser();
        void ReadManual(std::string fn);
        std::string GetManual();
};


#endif //PROJECT_3_EMOJI_ARGPARSER_H
