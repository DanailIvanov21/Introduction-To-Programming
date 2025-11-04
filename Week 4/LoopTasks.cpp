#include <iostream>
// Задача 1
int main() {
    unsigned number, searchDigit;
    std::cin >> number >> searchDigit;

    unsigned count = 0;
    while (number > 0) {
        unsigned currentDigit = number % 10;
        if (currentDigit == searchDigit)
            count++;
        number /= 10;
    }

    std::cout << count;
}


// Задача 2
int main() {
    unsigned original;
    std::cin >> original;

    unsigned sortedNumber = 0;
    unsigned tempOriginal;

    for (unsigned digit = 1; digit <= 9; digit++) {
        tempOriginal = original;
        while (tempOriginal > 0) {
            unsigned currentDigit = tempOriginal % 10;
            if (currentDigit == digit)
                sortedNumber = sortedNumber * 10 + digit;
            tempOriginal /= 10;
        }
    }

    std::cout << sortedNumber;
}

// Задача 3
int main() {
    unsigned K, start, end;
    std::cin >> K >> start >> end;

    for (unsigned current = start; current <= end; current++) {
        unsigned temp = current;
        bool isSpecial = true;

        while (temp > 0) {
            unsigned digit = temp % 10;
            if (digit == 0 || K % digit != 0) {
                isSpecial = false;
                break;
            }
            temp /= 10;
        }

        if (isSpecial)
            std::cout << current << " ";
    }
}

// Задача 4
#include <iostream>
int main() {
    unsigned num;
    std::cin >> num;

    
    unsigned reversed = 0, temp = num, digits = 0;
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
        digits++;
    }

    
    unsigned skip1, skip2;
    if (digits % 2 == 0) {
        skip1 = digits / 2;       
        skip2 = skip1 + 1;        
    } else {
        skip1 = (digits + 1) / 2; 
        skip2 = skip1;
    }

    
    unsigned newNumber = 0;
    unsigned position = 1; 
    temp = reversed;

    while (temp > 0) {
        unsigned digit = temp % 10;
        if (!(position == skip1 || position == skip2))
            newNumber = newNumber * 10 + digit;
        temp /= 10;
        position++;
    }

    std::cout << newNumber << " " << newNumber + 1;
}

