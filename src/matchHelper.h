//
// Created by Andrew Beers on 1/5/25.
//

#ifndef GREP_STARTER_CPP_MATCHHELPER_H
#define GREP_STARTER_CPP_MATCHHELPER_H

#include <string>
#include <unordered_set>

const std::unordered_set<char> digits({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
const std::unordered_set<char> uppercaseLetters({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                                 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                                                 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'});
const std::unordered_set<char> lowercaseLetters({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                                                 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                                                 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'});


bool containsDigit(std::string input){
    for(char curr : input){
        if (digits.find(curr) != digits.end()){
            return true;
        }
    }

    return false;
}

bool containsUppercaseLetter(std::string input){
    for(char curr : input){
        if (uppercaseLetters.find(curr) != uppercaseLetters.end()){
            return true;
        }
    }

    return false;
}

bool containsLowercaseLetter(std::string input){
    for(char curr : input){
        if (lowercaseLetters.find(curr) != lowercaseLetters.end()){
            return true;
        }
    }

    return false;
}



#endif //GREP_STARTER_CPP_MATCHHELPER_H
