#include <iostream>

bool isDigit(char c) {
    c = tolower(c); 
    return (c >= 'a' && c <= 'z' && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
}

void removeWords(char* text, int length) {
    char result[1024];
    int resultIndex = 0;
    bool firstWord = true;

    for (int i = 0; text[i] != '\0';) {
        int start = i; 
        while (text[i] == ' ') {
            i++;
        }
        start = i; 
        while (text[i] != ' ' && text[i] != '\0') {
            i++;
        }
        int wordLength = i - start;

        if (!(wordLength == length && isDigit(text[start]))) {
            if (!firstWord) {
                result[resultIndex++] = ' ';
            }
            firstWord = false;
            for (int j = start; j < i; j++) {
                result[resultIndex++] = text[j];
            }
        }
    }

    result[resultIndex] = '\0';
    for (int i = 0; i <= resultIndex; i++) {
        text[i] = result[i];
    }
}

int main() {
    char text[1024];
    int length;

    std::cout << "Input text: ";
    std::cin.getline(text, 1024);
    
    std::cout << "input size of delete: ";
    std::cin >> length;

    removeWords(text, length);
    std::cout << "Result text : " << text << std::endl;

    return 0;
}