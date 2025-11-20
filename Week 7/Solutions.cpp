#include <iostream>
using namespace std;

const int SIZE = 100;

int getValueFromChar(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    return ch - 'A' + 10;
}

char getCharFromValue(int n) {
    if (n >= 0 && n <= 9) {
        return '0' + n;
    }
    return n + 'A' - 10;
}

void increment(char arr[], int size, int k) {

    int cur = size - 1;
    bool carry = getValueFromChar(arr[cur]) == k - 1;

    while (carry) {
        if (getValueFromChar(arr[cur]) != k - 1)
            break;
        arr[cur] = '0';
        cur--;
    }

    if (arr[cur] == '9') {
        arr[cur] = 'A';
    }
    else {
        arr[cur]++;
    }
}

void decrement(char arr[], int size, int k) {

    int cur = size - 1;
    bool carry = arr[cur] == '0';

    while (carry) {
        if (arr[cur] != '0')
            break;
        arr[cur] = getCharFromValue(k - 1);
        cur--;
    }

    if (arr[cur] == 'A') {
        arr[cur] = '9';
    }
    else {
        arr[cur]--;
    }
}

void add(char a[], char b[], int size, int k, char res[]) {

    int carry = 0;

    for (int i = size - 1; i >= 0; i--) {

        int valA = getValueFromChar(a[i]);
        int valB = getValueFromChar(b[i]);

        int sum = valA + valB + carry;

        carry = sum / k;
        sum = sum % k;

        res[i] = getCharFromValue(sum);
    }

}


// for tasks 4 and 5 check the NumericSystemsConverter
int main() {

    const int SIZE = 4;
    char arr1[SIZE] = { '0','1', '7', '5' };
    char arr2[SIZE] = { '0','5', '3', '7' };
    char res[SIZE] = { '0','0','0','0' };
    //decrement(arr, 3, 2);
    add(arr1, arr2, SIZE,8 , res);

    for (size_t i = 0; i < SIZE; i++)
    {
        cout << res[i];
    }

    return 0;
}

