#include <iostream>
#include <cstring>


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
    // 2. To build executable in command line, enter "g++ --std=c++11 -g src/*.cpp -o output/emo-yzer.ex"
    // 3. To run executable, enter "./output/emo-yzer <commands>"

// DEBUGGING PROGRAM IN CLION:
    // 1. Next to the hammer/build button, click on the "<your project title> | Debug" button
    // 2. Click on "Edit configurations"
    // 3. In "Program arguments:", enter the arguments you want to run on the program
    // 4. In "Working directory:", enter the absolute file path to "emoji-analyzer" directory
        // Ex. C:\Users\spcie\CLionProjects\project-3-emoji\emoji-analyzer
    // 5. Click "Apply" and press "Okay" to save configuration


int main(int argc, char* argv[]) {
    // Check help
    if ( (argc == 1) || ((std::string)argv[1] == "--help") && (argc == 2)) {
        std::cout << "Project 3: The Emoji Analyzer, Summer 2023" << std::endl;
        std::cout << "Usage:" << std::endl;
        std::cout << "\t./output/emo-yzer.ex [command] [option] [...]" << std::endl;
    }

    // Dummy code, remove later
    std::cout << std::endl;
    for (int k = 0; k < argc; k++) {
        std::cout << "argv[" << k << "]: " << (std::string) argv[k] << std::endl;
    }

    // 1st arg = Command
    int i = 1;
    std::string command = (std::string)(argv[i]);

    // Following arg = Options & positional arguments
    i++;
    if (command == "search") {
        std::string name = argv[i];   // IG username
        if (name[0] != '@') {
            // Removes '@' symbol from username
            name = name.substr(1);
            // search(name);
        }
        else {
            // search(name);
        }
        exit(0);
    }

    else if (command == "list") {
        // list()
        exit(0);
    }

    else if (command == "num") {
        std::string name = argv[i];
        if (name == "-all") {
            // Users.GetNumDataPoints
        }
        else if (name[0] != '@') {
            // Removes '@' symbol from arg
            name = name.substr(1);
            // User& user = Users.GetUser(name);
            // user.GetNumDataPoints
        }
        else {
            // User& user = Users.GetUser(name);
            // user.GetNumDataPoints
        }
        exit(0);
    }


    else if (command == "sort") {
        std::string sortMeth;
        std::string user;
        bool flagUsage = false;
        std::string usageVal;
        bool flagReverse = false;
        bool flagName = false;

        // Parses through argument options. Order of inserting options doesn't matter
        while (i < argc) {
            std::string option = (std::string)argv[i];
            if (option == "-quick") {
                sortMeth = "quick";
            }
            else if (option == "-merge") {
                sortMeth = "merge";
            }
            else if (option == "-all") {
                user = "all";
            }
            else if (option[0] == '@') {
                user = option.substr(1);
            }
            else if (option == "-usage") {
                flagUsage = true;
            }
            else if (option[0] == ':' && option[-1] == ':') {
                usageVal = option;
            }
            else if (option == "-reverse") {
                flagReverse = true;
            }
            else if (option == "-name") {
                flagName = true;
            }

            else {
                std::cout << "Error: " << option << "is not a recognised sorting method";
                exit(1);
            }
            i++;

        }

    }
    else if (command == "man") {
        // parse.PrintManual():
    }
    else {
        std::cout << "Error: " << command << " is not a recognised command.";
        exit(1);
    }

}
