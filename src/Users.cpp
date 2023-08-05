//
// Created by spcie on 8/5/2023.
//

#include "Users.h"

Users::Users() {
    users = {};
}

void Users::ReadUsers(const std::string& fn) {
    // Reads users.txt
    std::ifstream inFS(fn);

    if (inFS) {   // If file is open
        std::string line;
        while (!inFS.eof()) {   // Reads each user line by line
            getline(inFS, line);
            users.insert(line);
        }

    }
    else {
        std::cout << "Could not open file :(" << std::endl;
        exit(1);
    }
}
bool Users::UserExists(const std::string& user) {
    // Checks if user is in local database
    if (users.find(user) != users.end()) {
        return true;
    }
    else {
        return false;
    }
}
void Users::PrintUsers() {
    // Prints list of users sorted alphabetically
    for (const std::string& u : users) {
        std::cout << u << std::endl;
    }
}