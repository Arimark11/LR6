#include <iostream>

bool isDigit(char a){
    return a >= '0' && a <= '9';
}

bool isFloatCharacter(char c) {
    return isDigit(c) || c == '.' || c == '+' || c == '-' || c == ',';
}

void extractFloat(const char* input, char* output) {
    bool decimalPointFound = false;
    bool numberStarted = false;
    int i = 0;

    while (*input) {
        char c = *input;

        if (isFloatCharacter(c)) {
            if (isDigit(c)) {
                output[i++] = c;
                numberStarted = true; 
            } else if (c == '.') {
                if (!decimalPointFound) {
                    output[i++] = c;
                    decimalPointFound = true;
                }
            } else if ((c == '+' || c == '-') && !numberStarted) {
                output[i++] = c; 
            }
        } else {
            if (numberStarted) {
                break;
            }
        }
        input++;
    }

    output[i] = '\0';
}


int main() {
    const int maxSize = 100; 
    char input[256]; 
    char floatNumber[maxSize]; 

    std::cout << "input string : ";
    std::cin.getline(input, 256);

    extractFloat(input, floatNumber);

    if (floatNumber[0] != '\0') {
        std::cout << "float : " << floatNumber << std::endl;
    }else {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}