#include <iostream>


int absoluteValue(int n) { //връща | number |
    return n > 0 ?  n : -n;
}

bool isBetween(char symbol, char from, char to) {
    return symbol >= from && symbol <= to;
}

bool isDigit(char symbol) { //връща дали символът е цифра
    return isBetween(symbol, '0', '9');
}

bool isLetter(char symbol) { //връща дали символът е буква
    return isBetween(symbol, 'a', 'z') || isBetween(symbol, 'A', 'Z');
}

char toUpper(char symbol) { // ако буквата е малка връща съответната и главна
    return symbol - 'a' + 'A';
}

char toLower(char symbol) {  //ако буквата е главна връща съответната и малка
    return symbol - 'A' + 'a';
}

int toNumber(char symbol) { //конвертира от символ в цифра
    return symbol - '0';
}

char toCharacter(int number) { //конвертира от цифра в символ
    return number + '0';
}

int power(int base, unsigned int exponent) { // връща base^exponent
    int res = 1;

    for (int i = 0; i < exponent; i++)
    {
       res *= base
    }
    return res;
}

bool isPrime(unsigned int number) { //проверява дали дадено число е просто
    int sqrtOfNum = sqrt(number);
    for (int j = 2; j <= sqrtOfNum; j++)
    {
        if (number % j == 0)
        {
            return false;
        }
    }
    return true;
}

short getLength(int number) { //връща колко цифри има даденото число
    if (!number)
        return 1;

    int curLength = 0;

    while (number) {
        curLength++;
        number /= 10;
    }

    return curLength;
}


int main() {

    std::cout << toUpper('d');

}
