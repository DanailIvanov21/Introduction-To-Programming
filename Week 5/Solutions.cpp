#include <iostream>
using namespace std;
// Задача 1
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) 
            return false;       
    }
    return true; 
}

int main() {
    int arr1[] = {5, 7, 4, 9};
    int arr2[] = {1, 2, 3, 4};
    cout << boolalpha << isSorted(arr1, 4) << endl; // false
    cout << boolalpha << isSorted(arr2, 4) << endl; // true
}


// Задача 2
void swapByRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;
    int arr[30];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    swapByRef(arr[minIndex], arr[maxIndex]);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}



// Задача 3
void reverseFirstN(int arr[], int n, int N) {
    for (int i = 0; i < N / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[N - 1 - i];
        arr[N - 1 - i] = temp;
    }
}

int main() {
    int arr[] = {1, -4, 4, -5, -9, 2, 10};
    reverseFirstN(arr, 7, 4);

    for (int i = 0; i < 7; i++) cout << arr[i] << " ";
}




// Задача 4
void removeAt(int arr[], int &n, int index) {
    for (int i = index; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main() {
    int arr[] = {33, 1, 23, 8, 54, 5, 1, 6};
    int n = 8, index = 3;

    removeAt(arr, n, index);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}



// Задача 5
bool isSymmetric(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i])
            return false;
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 2, 1};
    int arr2[] = {1, 2, 3, 4, 1};
    cout << (isSymmetric(arr1, 5) ? "yes" : "no") << endl;
    cout << (isSymmetric(arr2, 5) ? "yes" : "no") << endl;
}



// Задача 6
int longestSequence(int arr[], int n) {
    int maxLen = 1, currentLen = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            currentLen++;
        else
            currentLen = 1;
        if (currentLen > maxLen)
            maxLen = currentLen;
    }
    return maxLen;
}

int main() {
    int arr[] = {3, 3, 2, 2, 2, 5, 2, 2, 3, 3, 3};
    cout << longestSequence(arr, 11);
}



// Задача 7
void removeNegatives(int arr[], int &n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            arr[j++] = arr[i];
    }
    n = j;
}

int main() {
    int arr[] = {1, -4, 4, -5, -9, 2, 10};
    int n = 7;
    removeNegatives(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}



// Задача 8
bool isSubarray(int a[], int n, int b[], int m) {
    for (int i = 0; i <= n - m; i++) {
        bool found = true;
        for (int j = 0; j < m; j++) {
            if (a[i + j] != b[j]) {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    return false;
}

int main() {
    int a[] = {1, 4, 4, 0, 4, 2};
    int b[] = {4, 0, 4};
    cout << boolalpha << isSubarray(a, 6, b, 3);
}



// Задача 9
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int arr[30];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = digitSum(arr[i]);
        if (sum >= 10 && sum <= 99)
            count++;
    }

    if (count == 0)
        cout << "No such numbers";
    else
        cout << count;
}



// Задача 10
bool isPermutation(int arr1[], int arr2[], int n) {
    int freq1[10] = {0}; 
    int freq2[10] = {0};

    for (int i = 0; i < n; i++) {
        freq1[arr1[i]]++;
        freq2[arr2[i]]++;
    }

    for (int i = 0; i < 10; i++) {
        if (freq1[i] != freq2[i])
            return false; 
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int arr1[10], arr2[10];
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) cin >> arr2[i];

    if (isPermutation(arr1, arr2, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}




// Задача 11
bool isPalindrome(int arr[], int start, int end) {
    while (start < end) {
        if (arr[start] != arr[end])
            return false;
        start++;
        end--;
    }
    return true;
}

bool isConcatOfTwoPalindromes(int arr[], int n) {
    
    for (int i = 0; i < n; i++) {
        if (isPalindrome(arr, 0, i) && isPalindrome(arr, i + 1, n - 1))
            return true;
    }
    
    return isPalindrome(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (isConcatOfTwoPalindromes(arr, n))
        cout << "true";
    else
        cout << "false";
}

// Задача 12
int countInversions(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                count++;
    return count;
}

int main() {
    int arr[] = {5, 4, 3, 2, 1, 0};
    cout << countInversions(arr, 6);
}



// Задача 13
void makeZigZag(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) { 
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        } else { 
            if (arr[i] < arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    makeZigZag(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}



// Задача 14
bool checkSumEqualMax(int arr[], int n) {
    int max = arr[0], sum = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return max == sum - max;
}

int main() {
    int arr[] = {8, 9, 17, 53, 12, 7};
    cout << (checkSumEqualMax(arr, 6) ? "Yes" : "No");
}



// Задача 15

void removeAll(int arr[], int &n, int x) {
    int j = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != x)
            arr[j++] = arr[i];
    n = j;
}

int main() {
    int n, x;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    removeAll(arr, n, x);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

