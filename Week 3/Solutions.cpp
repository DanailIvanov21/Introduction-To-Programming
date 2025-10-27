#include <iostream>
// Задача 1
int main() {
    int a, b;
    std::cin >> a >> b;

    for (int i = a; i <= b; i++) {
        bool isPrime = true;  

       
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = false;  
                break;
            }
        }

        if (isPrime && i > 1)  
            std::cout << i << " ";
    }
}

// Задача 2
int main() {
    int n, reversed = 0, temp;
    std::cin >> n;
    temp = n;

    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    std::cout << (reversed == n ? 1 : 0);
}
// Задача 3
int main() {
    int n;
    std::cin >> n;

    int fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;

    std::cout << fact;
}
// Задача 4


// Задача 5

// Задача 6

// Задача 7
