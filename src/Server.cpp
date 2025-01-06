#include <iostream>
#include <string>
#include <unordered_set>

bool match_pattern(const std::string& input_line, const std::string& pattern) {
    const std::unordered_set<char> digits({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
    const std::unordered_set<char> uppercaseLetters({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                               'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                                               'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'});
    const std::unordered_set<char> lowercaseLetters({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                                               'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                                               'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'});
    if (pattern.length() == 1) {
        return input_line.find(pattern) != std::string::npos;
    }
    else if (pattern == "\\d"){
        for(char curr : input_line){
            if (digits.find(curr) != digits.end()){
                return true;
            }
        }

        return false;
    }
    else if (pattern == "\\w"){
        for(char curr : input_line){
            if (digits.find(curr) != digits.end()){
                return true;
            }

            if (uppercaseLetters.find(curr) != uppercaseLetters.end()){
                return true;
            }

            if (lowercaseLetters.find(curr) != lowercaseLetters.end()){
                return true;
            }

            if (curr == '_'){
                return true;
            }
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
