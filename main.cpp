#include <iostream>
#include "argspp/src/args.h";

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
}
