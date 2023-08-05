#include <iostream>

#include "ArgParser.h"
#include "Users.h"

// FILE STRUCTURE:
    // ../emoji-analyzer/
        // argspp
        // input
        // output
        // src
        // <misc>
            // "<>" = Elements inside this will vary

// RUNNING PROGRAM IN COMMAND LINE:
    // 1. Change directory (cd) into "../emoji-analyzer"
        // ".." = Parent directory. Will vary depending on how you organize your files
    // 2. To build executable in command line, enter "g++ --std=c++11 -g src/*.cpp -o output/emo-yzer.exe"
    // 3. To run executable, enter "./output/emo-yzer.exe <commands>"

// DEBUGGING PROGRAM IN CLION:
    // 1. Next to the hammer/build button, click on the "<your project title> | Debug" button
    // 2. Click on "Edit configurations"
    // 3. In "Program arguments:", enter the arguments you want to run on the program
    // 4. In "Working directory:", enter the absolute file path to "emoji-analyzer" directory
        // Ex. C:\Users\spcie\CLionProjects\project-3-emoji\emoji-analyzer
    // 5. Click "Apply" and press "Okay" to save configuration

int main(int argc, char* argv[]) {
    ArgParser parser;
    Users users;
    parser.ReadManual("input/cmd-manual.txt");
    users.ReadUsers("input/users.txt");


    // Check help
    if ( (argc == 1) || ((std::string)argv[1] == "--help") && (argc == 2)) {
        std::cout << "THE EMOJI-ANALYZER" << std::endl;
        std::cout << "An Instagram post analyzer — for emojis!" << std::endl;
        std::cout << "To get started, enter \"man\" in the command line to get a list of commands" << std::endl;
    }

    // 1st arg = Command
    int i = 1;
    std::string command = (std::string)(argv[i]);

    // Following arg = Options & positional arguments
    // CLI ignores arguments after the arguments are registered

    if (command == "search") {
        if (argc == 2) {
            std::cout << "Error: " << command << " needs an additional argument." << std::endl;
            exit(1);
        }

        i++;
        std::string option = argv[i];   // IG username
        if (option.substr(0,7) == "-user=@") {
            std::string name = option.substr(7);
            if (users.UserExists(name)) {
                std::cout << "Found @" << name << " in local database." << std::endl;
            }
            else {
                std::cout << "Could not find @" << name << " in local database." << std::endl;
                std::cout << "Hint: Enter \"list\" in command line to get list of all users in local database" << std::endl;
            }
            exit(0);
        }
        else {
            std::cout << "Error: " << option << " is not a recognized option";
            exit(1);
        }
    }

    else if (command == "list") {
        users.PrintUsers();
        exit(0);
    }

    else if (command == "dpoints") {
        if (argc == 2) {
            // std::cout << users.GetNumDataPoints << std::endl;
            exit(0);
        }

        i++;
        std::string option = argv[i];
        if (option == "-all") {
            // std::cout << users.GetNumDataPoints << std::endl;
            exit(0);
        }

        else {
            std::cout << "Error: " << option << " is not a recognized option";
            exit(1);
        }
    }

    else if (command == "sort") {
        if (argc == 2) {
            std::cout << "Error: " << command << " needs an additional argument." << std::endl;
            exit(1);
        }

        // Positional argument: Needs to be entered after "sort" command
        std::string sortMeth;

        // Default option values
            // Order of options can vary + Whether they're included in argv is optional
        std::string user = "all";
        std::string metric = "usage";
        std::string emoji = "none";
        int lines = 10;

        i++;
        sortMeth = argv[i];
        if (sortMeth == "-quick" || sortMeth == "-merge") {
            if (sortMeth == "-quick") {
                sortMeth = "quick";
            }
            else if (sortMeth == "-merge") {
                sortMeth = "merge";
            }

            if (argc == 3) {   // ex. "./emo-yzer.exe sort -merge"
                // vector<Caption> sortedCap = sort(sortMeth, user, metric, emoji);
                // print(sortedCap);
                std::cout << "sortMeth: " << sortMeth << std::endl;
                std::cout << "user: " << user << std::endl;
                std::cout << "metric: " << metric << std::endl;
                std::cout << "emoji: " << emoji << std::endl;
                std::cout << "lines: " << lines << std::endl;
                exit(0);
            }

            // vector<Caption> sortedCap = sort(sortMeth, user, metric, emoji)
            // print(sortedCap);
            exit(0);
        }
        else {
            std::cout << "Error: " << sortMeth << " is not a recognized sorting method";
            exit(1);
        }
    }

    else if (command == "man") {
        std::cout << parser.GetManual();
    }

    else {
        std::cout << "Error: " << command << " is not a recognized command.";
        exit(1);
    }
}

