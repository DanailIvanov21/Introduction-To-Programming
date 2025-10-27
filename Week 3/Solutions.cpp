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
int main() {
    int a, b;
    std::cin >> a >> b;

    for (int i = a; i <= b; i++) {
        int current = i;
        bool flag = true;

        while (current > 0 && flag) {
            int last = current % 10;
            int tmp = current / 10;
            while (tmp > 0) {
                if (tmp % 10 == last)
                {
                    flag = false;
                    break;
                }
                tmp /= 10;
            }
            current /= 10;
        }
        if (flag) std::cout << i << " ";
    }
}

// Задача 5
int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) std::cout << i << " ";
    }
}
// Задача 6
int main() {
    int sum = 0, current;
    do {
        std::cin >> current;
        sum += current;
    } while (current != 0);

    std::cout << sum;
}
// Задача 7
int main() {
    int n;
    std::cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        int digit;
        std::cin >> digit;
        if (digit % 2 == 0)
        {
            result = result * 10 + digit;
        }
    }
    std::cout << result * 2;
}

// Задача 8
int main() {
    int n;
    std::cin >> n;
    int a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        std::cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
}
// Задача 9
int main() {
    int n;
    std::cin >> n;

    int mostFreqDigit = 0;   
    int maxCount = 0;      

    int currentDigit = 0;    
    
    while (currentDigit <= 9) {
        int temp = n;        
        int count = 0;       

        while (temp > 0) {
            int last = temp % 10;
            if (last == currentDigit)
                count++;
            temp /= 10;
        }

        if (count > maxCount || (count == maxCount && currentDigit < mostFreqDigit)) {
            maxCount = count;
            mostFreqDigit = currentDigit;
        }

        currentDigit++;
    }

    std::cout << mostFreqDigit;
}
// Задача 10
int main() {
    int a, b;
    std::cin >> a >> b;

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Алгоритъм на Евклид
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    std::cout << a;
}
// Задача 11
int main() {
    int n;
    std::cin >> n;

    int count = 0, temp = n;


    while (temp > 0) {
        temp /= 10;
        count++;
    }

    int remove1 = count / 2 + (count % 2 == 0 ? 0 : 1); 
    int remove2 = (count % 2 == 0) ? remove1 + 1 : remove1; 

    int newNum = 0, power = 1;
    int pos = 0;

    while (n > 0) {
        pos++;
        int digit = n % 10;
        if (pos != remove1 && pos != remove2) {
            newNum = digit * power + newNum;
            power *= 10;
        }
        n /= 10;
    }

    std::cout << newNum << ", " << newNum + 1;
}
// Задача 12
int main() {
    int n;
    std::cin >> n;

    for (int i = 2; i <= n / 2; i++) 
        bool firstPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                firstPrime = false;
                break;
            }
        }
        bool secondPrime = true;
        int k = n - i;
        for (int j = 2; j * j <= k; j++) {
            if (k % j == 0) {
                secondPrime = false;
                break;
            }
        }

        if (firstPrime && secondPrime)
            std::cout << n << " = " << i << " + " << n - i << std::endl;
    }
}

// Задача 13
int main() {
    int n;
    std::cin >> n;

    int max1 = -1, max2 = -1, number;

    for (int i = 0; i < n; i++) {
        std::cin >> number;
        if (number > max1) {
            max2 = max1;
            max1 = number;
        } else if (number > max2 && number != max1) {
            max2 = number;
        }
    }

    std::cout << max1 << " " << max2;
}
