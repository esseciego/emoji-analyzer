#include <iostream>
#include "../argspp/src/args.h"

// FILE STRUCTURE:
    // ../emoji-analyzer/
        // argspp
        // input
        // output
        // src
        // <msc>

// RUNNING PROGRAM IN COMMAND LINE:
    // 1. Change directory (cd) into "../emoji-analyzer"
    // 2. To build executable, type "g++ --std=c++11 -g src/*.cpp argspp/src/args.cpp -o output/emo-yzer" into command line
    // 3. To run executable, type "./output/emo-yzer <commands>" into command line

using namespace args;

int main(int argc, char* argv[]) {
    // Creates parser instance
    ArgParser parser;
    parser.helptext = "The Emoji Analyzer";

    // Registers commands, options, and flags
    parser.command("search");

    parser.command("list");
    parser.option("all");

    parser.command("num");
    parser.option("data-points d");

    parser.command("mergesort");
    parser.command("quicksort");
    parser.option("usage u");
    parser.option("reverse r");
    parser.flag("name");

    parser.command("man");

    // Parse array of string arguments
    parser.parse(argc, argv);

    // Prints parser's state to stdout
    parser.print();
}
