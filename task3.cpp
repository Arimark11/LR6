#include <iostream>

void intToString(int number, char* str) {
    int i = 0;
    bool isNegative = false;

    if (number < 0) {
        isNegative = true;
        number = -number;
    }

    while (number > 0){
        str[i++] = (number % 10) + '0';
        number /= 10;
    };

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

int stringToInt(const char* str) {
    int result = 0;
    bool isNegative = false;

    if (*str == '-') {
        isNegative = true;
        str++;
    }

    while (*str) {
        result = result * 10 + (*str - '0');
        str++;
    }

    return isNegative ? -result : result;
}

void floatToString(float number, char* str) {
    int integerPart = 0;
    float fractionalPart = number;
    
    if (number < 0) {
        integerPart = -number;
        fractionalPart = number - integerPart;
    } else {
        while (fractionalPart >= 1.0) {
            integerPart++;
            fractionalPart -= 1.0;
        }
    }

    intToString(integerPart, str);
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    str[length++] = '.';

    for (int i = 0; i < 6; i++) {
        fractionalPart *= 10;
        int digit = 0;

        while (fractionalPart >= 1.0) {
            fractionalPart -= 1.0;
            digit++;
        }

        str[length++] = digit + '0';
        fractionalPart -= digit; 
    }

    str[length] = '\0';
}

double stringToFloat(const char* str) {
    double result = 0.0;
    double divisor = 1.0;
    bool isNegative = false;
    bool isFraction = false;

    if (*str == '-') {
        isNegative = true;
        str++;
    }

    while (*str) {
        if (*str == '.') {
            isFraction = true;
            str++;
            continue;
        }

        if (isFraction) {
            divisor *= 10.0;
            result += (*str - '0') / divisor;
        } else {
            result = result * 10 + (*str - '0');
        }
        str++;
    }

    return isNegative ? -result : result;
}

int main() {
    char intStr[20];
    char floatStr[20];
    
    int num = -12345;
    float fnum = -123.456789;

    intToString(num, intStr);
    std::cout << "Integer to string: " << intStr << std::endl;

    std::cout << "String to integer: " << stringToInt(intStr) << std::endl;

    floatToString(fnum, floatStr);
    std::cout << "Float to string: " << floatStr << std::endl;

    std::cout << "String to float: " << stringToFloat(floatStr) << std::endl;

    return 0;
}