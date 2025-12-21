#include <iostream>
using namespace std;
//1
size_t myStrlen(const char* s) {
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}
//2
void myStrcpy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

//3
void myStrcat(char* dest, const char* src) {
    while (*dest != '\0') {
        dest++;       
    }
    while (*src != '\0') {
        *dest = *src; 
        dest++;
        src++;
    }
    *dest = '\0';
}

//4
int myStrcmp(const char* a, const char* b) {
    while (*a != '\0' && *b != '\0') {
        if (*a < *b) return -1;
        if (*a > *b) return 1;
        a++;
        b++;
    }
    if (*a == '\0' && *b == '\0') return 0;
    if (*a == '\0') return -1;
    return 1;
}
//5
int myAtoi(const char* s) {
    int sign = 1;
    int num = 0;

    if (*s == '-') {
        sign = -1;
        s++;
    }

    while (*s != '\0') {
        num = num * 10 + (*s - '0');
        s++;
    }
    return num * sign;
}
//6
int countWords(const char* s) {
    int count = 0;
    bool inWord = false;

    while (*s != '\0') {
        if (*s != ' ' && !inWord) {
            inWord = true;
            count++;
        } else if (*s == ' ') {
            inWord = false;
        }
        s++;
    }
    return count;
}

//7
bool sameWords(const char* a, const char* b) {
    while (*a != '\0' && *b != '\0') {
        if (*a != *b) return false;
        a++;
        b++;
    }
    return *a == *b;
}
//8
void replaceChar(char* s, char what, char with) {
    while (*s != '\0') {
        if (*s == what)
            *s = with;
        s++;
    }
}

//9
void trunc(char* s, int n) {
    char* p = s;
    int count = 0;

    while (*p != '\0' && count < n) {
        p++;
        count++;
    }
    if (*p != '\0')
        *p = '\0';
}


//10
void delSymbol(char* s, char c) {
    char* write = s;

    while (*s != '\0') {
        if (*s != c) {
            *write = *s;
            write++;
        }
        s++;
    }
    *write = '\0';
}

//11
void toUpper(char* s) {
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z')
            *s -= ('a' - 'A'); // 32
        s++;
    }
}

int main() {
    /* Задача 1 */
    char s[] = "hello";
    cout << myStrlen(s);
    /* Задача 2 */
    char a[100] = "pine";
    char b[] = "apple";
    myStrcat(a, b);
    cout << a;
    /* Задача 3 */
    char a1[100] = "pine";
    myStrcat(a1, "apple");
    cout << "Task 3: " << a1 << endl;
    /* Задача 4 */
    cout << "Task 4: " << myStrcmp("three", "tree") << endl;

    /* Задача 5 */
    cout << "Task 5: " << myAtoi("-42") << endl;

    /* Задача 6 */
    cout << "Task 6: " << countWords("hello world") << endl;

    /* Задача 7 */
    cout << "Task 7: " 
         << (sameWords("hello", "hello") ? "Yes" : "No") << endl;

    /* Задача 8 */
    char a8[] = "Hello_world";
    replaceChar(a8, '_', ' ');
    cout << "Task 8: " << a8 << endl;

    /* Задача 9 */
    char a9[] = "Hello world";
    trunc(a9, 5);
    cout << "Task 9: " << a9 << endl;

    /* Задача 10 */
    char a10[] = "Hello world";
    delSymbol(a10, 'l');
    cout << "Task 10: " << a10 << endl;

    /* Задача 11 */
    char a11[] = "a1B2c@DeFg";
    toUpper(a11);
    cout << "Task 11: " << a11 << endl;

    return 0;
}
