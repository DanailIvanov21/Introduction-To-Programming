#include <iostream>
using namespace std;
// Задача 1

bool isPermutation(unsigned n1, unsigned n2) {
    for (int digit = 0; digit <= 9; digit++) {
        int count1 = 0, count2 = 0;
        unsigned temp1 = n1, temp2 = n2;
        while (temp1 > 0) {
            if (temp1 % 10 == digit)
                count1++;
            temp1 /= 10;
        }
        while (temp2 > 0) {
            if (temp2 % 10 == digit)
                count2++;
            temp2 /= 10;
        }
        if (count1 != count2)
            return false;
    }
    return true;
}

int main() {
    cout << boolalpha << isPermutation(352953, 295335) << endl; // true
    cout << isPermutation(123, 234) << endl; // false
}

// Задача 2

unsigned concat(unsigned a, unsigned b) {
    unsigned temp = b;
    unsigned p = 1;
    while (temp > 0) {
        p *= 10;
        temp /= 10;
    }
    return a * p + b;
}

int main() {
    cout << concat(19, 32) << endl; // 1932
}

// Задача 3

bool areDigitsSorted(unsigned number) {
    int previousDigit = number % 10; 
    number /= 10;                     

    bool isAscending = true;          
    bool isDescending = true;         
   
    while (number > 0) {
        int currentDigit = number % 10;

       
        if (currentDigit > previousDigit)
            isAscending = false;   

        if (currentDigit < previousDigit)
            isDescending = false;  

        previousDigit = currentDigit; 
        number /= 10;                 
    }


    return isAscending || isDescending;
}

int main() {
    cout << boolalpha;
    cout << areDigitsSorted(122239) << endl; 
    cout << areDigitsSorted(9871) << endl;   
    cout << areDigitsSorted(3142) << endl;   

// Задача 4

  int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    cout << max(1, 12) << endl; // 12
}

// Задача 5

  int max(int a, int b, int c, int d) {
    int m1 = (a > b) ? a : b;
    int m2 = (c > d) ? c : d;
    return (m1 > m2) ? m1 : m2;
}

int main() {
    cout << max(12, 4, 19, 7) << endl; // 19
}

// Задача 6

bool isPerfectSquare(unsigned n) {
    if (n == 0) return true;
    for (unsigned i = 1; i * i <= n; i++) {
        if (i * i == n)
            return true;
    }
    return false;
}

int main() {
    cout << (isPerfectSquare(24) ? "No" : "Yes") << endl; // No
    cout << (isPerfectSquare(25) ? "Yes" : "No") << endl; // Yes
}
