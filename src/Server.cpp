#include <iostream>
#include <string>
#include <unordered_set>

#include "matchHelper.h"

bool match_pattern(const std::string& inputLine, const std::string& pattern) {

    std::unordered_set<char> positiveMatches;
    std::unordered_set<char> negativeMatches;

    bool previousCharSlash = false;
    bool inBrackets = false;
    bool isNegative = false;


    if (pattern[0] == '['){
        for(int i = 1; i < pattern.size(); ++i){
            char patternChar = pattern[i];
            if (patternChar == '^'){
                isNegative = true;
            }
            else {
                if (isNegative){
                    negativeMatches.insert(patternChar);
                }
                else {
                    positiveMatches.insert(patternChar);
                }
            }
        }

        for(char inputChar : inputLine) {

            if (!negativeMatches.empty()){
                if (negativeMatches.find(inputChar) != negativeMatches.end()){
                    return false;
                }
                return true;
            }

            if (!positiveMatches.empty()){
                if (positiveMatches.find(inputChar) != positiveMatches.end()){
                    return true;
                }
                return false;
            }
        }
    }
    else if (pattern[0] == '^'){
        for(int i = 0; i < inputLine.size(); ++i) {
            if (i + 1 == pattern.size()){
                return true;
            }
            if (inputLine[i] != pattern[i + 1]){
                return false;
            }
        }

        return true;
    }
    else if (pattern[pattern.size() - 1] == '$'){
        for(int i = 0; i < inputLine.size(); i++){
            if (i == pattern.size() - 2){
                return true;
            }
            else{
                if (pattern[pattern.size() - i - 2] != inputLine[inputLine.size() - i - 1]){
                    return false;
                }
            }
        }

        return true;
    }
    else{
        size_t patternIndex = 0;

        for(char inputChar : inputLine) {
            if (patternIndex == pattern.size()) {
                return true;
            }

            if (pattern[patternIndex] == '\\') {
                if (pattern[patternIndex + 1] == 'd') {
                    if (digits.find(inputChar) != digits.end()) {
                        patternIndex += 2;
                        continue;
                    }
                } else if (pattern[patternIndex + 1] == 'w') {
                    if (digits.find(inputChar) != digits.end() ||
                        uppercaseLetters.find(inputChar) != uppercaseLetters.end() ||
                        lowercaseLetters.find(inputChar) != lowercaseLetters.end() ||
                        inputChar == '_') {
                        patternIndex += 2;
                        continue;
                    }
                }
            } else {
                if (pattern[patternIndex] == inputChar) {
                    patternIndex++;
                    continue;
                }

            }

            patternIndex = 0;
        }

        if (patternIndex == pattern.size()){
            return true;
        }

        return false;
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
