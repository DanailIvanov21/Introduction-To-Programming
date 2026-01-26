//1
bool haveDigit(int number, int digit) {

    if (number == 0)
        return false;

    if (number % 10 == digit)
        return true;

    return haveDigit(number / 10, digit);
}

//2
int sumOfArray(int arr[], int position, int size) {
    if (position == size)
        return 0;

    return arr[position] + sumOfArray(arr, position + 1, size);
}

//3
bool binarySearchRecursive(int arr[], int left, int right, int x) {
    if (left > right)
        return false;

    int mid = left + (right - left) / 2;

    if (arr[mid] == x)
        return true;
    else if (x < arr[mid])
        return binarySearchRecursive(arr, left, mid - 1, x);
    else
        return binarySearchRecursive(arr, mid + 1, right, x);
}

//4
bool isPalindrome(const char* str, int left, int right) {
    if (left >= right)
        return true;

    if (str[left] != str[right])
        return false;

    return isPalindrome(str, left + 1, right - 1);
}

//5
void countLetters(const char* str, int index, int& lower, int& upper) {
    if (str[index] == '\0')
        return;

    if (str[index] >= 'a' && str[index] <= 'z')
        lower++;
    else if (str[index] >= 'A' && str[index] <= 'Z')
        upper++;

    countLetters(str, index + 1, lower, upper);
}

//6
void swapCase(char* str, int index) {
    if (str[index] == '\0')
        return;

    if (str[index] >= 'a' && str[index] <= 'z')
        str[index] -= ('a' - 'A');
    else if (str[index] >= 'A' && str[index] <= 'Z')
        str[index] += ('a' - 'A');

    swapCase(str, index + 1);
}

//7
char firstUppercase(const char* str, int index) {
    if (str[index] == '\0')
        return '\0';

    if (str[index] >= 'A' && str[index] <= 'Z')
        return str[index];

    return firstUppercase(str, index + 1);
}

//8
int longestSequence(const char* str, int index, int current, int maxLen) {
    if (str[index] == '\0')
        return maxLen;

    if (str[index] == str[index - 1])
        current++;
    else
        current = 1;

    if (current > maxLen)
        maxLen = current;

    return longestSequence(str, index + 1, current, maxLen);
}

//9
int findNthOccurrence(const char* str, char ch, int n, int index) {
    if (str[index] == '\0')
        return -1;

    if (str[index] == ch)
        n--;

    if (n == 0)
        return index;

    return findNthOccurrence(str, ch, n, index + 1);
}
