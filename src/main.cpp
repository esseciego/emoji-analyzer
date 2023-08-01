#include <iostream>
#include "../argspp/src/args.h"

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
    // 2. To build executable in command line, enter "g++ --std=c++11 -g src/*.cpp argspp/src/args.cpp -o output/emo-yzer"
    // 3. To run executable, enter "./output/emo-yzer <commands>"

// DEBUGGING PROGRAM IN CLION:
    // 1. Next to the hammer/build button, click on the "<your project title> | Debug" button
    // 2. Click on "Edit configurations"
    // 3. In "Program arguments:", enter the arguments you want to run on the program
    // 4. In "Working directory:", enter the absolute file path to "emoji-analyzer" directory
        // Ex. C:\Users\spcie\CLionProjects\project-3-emoji\emoji-analyzer
    // 5. Click "Apply" and press "Okay" to save configuration

using namespace args;

int main(int argc, char* argv[]) {
    // Creates parser instance
    ArgParser parser;
    parser.helptext = "The Emoji Analyzer";

    // Registers commands, options, and flags
        // Options = Take in a value
            // Can be seperated by a space (ex. --opt 123) or equals symbol (--opt 123)
        // Flags = Take no values

    // FIXME: Not sure how to parse positional arguments (option's values)
    // FIXME: Not sure how to parse arguments starting with '-'

    parser.command("search");
    parser.option("user");

    parser.command("list");
    parser.option("all");

    parser.command("num");
    parser.option("points");

    parser.command("sort");
    parser.flag("merge");
    parser.flag("quick");
    parser.flag("usage");
    parser.flag("reverse");
    parser.flag("name");

    parser.command("man");

    // Parse array of string arguments
    parser.parse(argc, argv);

    // Prints parser's state to stdout
    parser.print();
}
