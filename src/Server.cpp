#include <iostream>
#include <string>
#include <unordered_set>

#include "matchHelper.h"

bool match_pattern(const std::string& input_line, const std::string& pattern) {

    std::unordered_set<char> positiveMatches;
    std::unordered_set<char> negativeMatches;

    bool previousCharSlash = false;
    bool inBrackets = false;
    bool isNegative = false;
    for(char inputChar : pattern){
        if (inputChar == '\\'){
            previousCharSlash = true;
        }
        else {
            if (previousCharSlash){
                if (inputChar == 'd'){
                    positiveMatches.insert(digits.begin(), digits.end());
                }
                else if (inputChar == 'w'){
                    positiveMatches.insert(digits.begin(), digits.end());
                    positiveMatches.insert(uppercaseLetters.begin(), uppercaseLetters.end());
                    positiveMatches.insert(lowercaseLetters.begin(), lowercaseLetters.end());
                    positiveMatches.insert('_');
                }
            }
            else {
                if (inputChar == '['){
                    inBrackets = true;
                }
                else if (inputChar == ']'){
                    inBrackets = false;
                }

                if (inBrackets){

                    if (inputChar == '^'){
                        isNegative = true;
                    }
                    else {
                        if (isNegative){
                            negativeMatches.insert(inputChar);
                        }
                        else {
                            positiveMatches.insert(inputChar);
                        }
                    }
                }
            }
            previousCharSlash = false;
        }
    }

    if (pattern.length() == 1) {
        return input_line.find(pattern) != std::string::npos;
    }
    else if (!positiveMatches.empty()){
        for(char inputChar : input_line){
            if (positiveMatches.find(inputChar) != positiveMatches.end()){
                return true;
            }
        }

        for(char inputChar : input_line){
            if (negativeMatches.find(inputChar) != positiveMatches.end()){
                return false;
            }
        }

        if (!negativeMatches.empty()){
            return true;
        }

        return false;
    }
    else {
        throw std::runtime_error("Unhandled pattern " + pattern);
    }
}

int main(int argc, char* argv[]) {
    // Flush after every std::cout / std::cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // You can use print statements as follows for debugging, they'll be visible when running tests.
    std::cerr << "Logs from your program will appear here" << std::endl;

    if (argc != 3) {
        std::cerr << "Expected two arguments" << std::endl;
        return 1;
    }

    std::string flag = argv[1];
    std::string pattern = argv[2];

    if (flag != "-E") {
        std::cerr << "Expected first argument to be '-E'" << std::endl;
        return 1;
    }

     std::string input_line;
     std::getline(std::cin, input_line);

     try {
         if (match_pattern(input_line, pattern)) {
             return 0;
         } else {
             return 1;
         }
     } catch (const std::runtime_error& e) {
         std::cerr << e.what() << std::endl;
         return 1;
     }
}
