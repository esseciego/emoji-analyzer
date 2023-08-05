//
// Created by spcie on 8/5/2023.
//

#ifndef PROJECT_3_EMOJI_USERS_H
#define PROJECT_3_EMOJI_USERS_H

#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Users {
    private:
        std::set<std::string> users;
    public:
        Users();
        void ReadUsers(const std::string& fn);
        void SearchUsers(const std::string& user);
        void PrintUsers();
};


#endif //PROJECT_3_EMOJI_USERS_H
