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
    // CLI ignores arguments after the appropriate

    if (command == "search") {
        if (argc == 2) {
            std::cout << "Error: " << command << " needs an additional argument." << std::endl;
            exit(1);
        }

        i++;
        std::string option = argv[i];   // IG username
        if (option.substr(0,7) == "-user=@") {
            std::string name = option.substr(7);
            // search(name);
            // if (search(name)) {
                // std::cout << "@" << name << " was found in the local database!
            // else {
                // std::cout << "@" << name << " was not found in the local database!
                // std::cout << "Hint: Enter "list" to get the list of users in the local database.
            exit(0);
        }
        else {
            std::cout << "Error: " << option << " is not a recognized option";
            exit(1);
        }
    }

    else if (command == "list") {
        // list()
        exit(0);
    }

    else if (command == "dpoints") {
        if (argc == 2) {
            // std::cout << users.GetNumDataPoints << std::endl;
            std::cout << "GETTING ALL" << std::endl;
            exit(0);
        }

        i++;
        std::string option = argv[i];
        if (option == "-all") {
            // std::cout << users.GetNumDataPoints << std::endl;
            std::cout << "GETTING ALL" << std::endl;
            exit(0);
        }
        else if (option.substr(0,7) == "-user=@") {
            std::string name = option.substr(7);
            // User& user = Users.GetUser(name);
            // std::cout << user.GetNumDataPoints << std::endl;
            std::cout << "GETTING " << name << std::endl;
            exit(0);
        }
        else {
            std::cout << "Error: " << option << " is not a recognized option";
            exit(1);
        }
    }


    else if (command == "sort") {
        std::string sortMeth;
        std::string user = "all";
        std::string metric = "usage";
        std::string emoji = "none";

        sortMeth = argv[i];   // sortMeth: Positional argument (needs to be entered after "sort")
        if (sortMeth == "-quick") {
            i++;
            while (i < argc) {   // Order of options + whether they're included in command is optional
                std::string option = argv[i];
                if (option == "-all") {
                    user = "all";
                }
                else if (option[0] == '@') {
                    user = option.substr(1);
                }
                else if (option == "-usage") {
                    metric = "usage";
                }
                else if (option[0] == ':' && option[-1] == ':') {
                    emoji = option;
                }
                else {
                    std::cout << "Error: " << option << "is not a recognized option";
                    exit(1);
                }
                i++;
            }
            // sort(sortMeth, user, metric, emoji)

            // TODO: Remove dummy code
            std::cout << "sortMeth: " << sortMeth << std::endl;
            std::cout << "user: " << user << std::endl;
            std::cout << "metric: " << metric << std::endl;
            std::cout <<  "emoji: " << emoji << std::endl;
        }
        else if (sortMeth == "-merge") {
            i++;
        }
        else {
            std::cout << "Error: " << sortMeth << "is not a recognized option";
            exit(1);
        }
    }

    else if (command == "man") {
        // parse.PrintManual():
    }

    else {
        std::cout << "Error: " << command << " is not a recognized command.";
        exit(1);
    }
}
