#include <iostream>
using namespace std;
const int MAX = 10;

//1
int minElement(int a[][MAX], int rows, int cols) {
    int min = a[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }
    return min;
}

//2
void printDiagonals(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i][i] << " ";
    }
    cout << endl;
  
    for (int i = 0; i < n; i++) {
        cout << a[i][n - 1 - i] << " ";
    }
    cout << endl;
}


//3
void printAboveBelowDiagonal(int a[][MAX], int n) {
    cout << "Above diagonal:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;

    cout << "Below diagonal:" << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;
}

//4
void printZigZag(int a[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                cout << a[i][j] << " ";
            }
        } else {
            for (int j = cols - 1; j >= 0; j--) {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
}


//5
bool isUpperTriangular(int a[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

//6
void transpose(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

//7
bool isSymmetric(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    return true;
}

//8
bool isMagicSquare(int a[][MAX], int n) {
    int sum = 0;

    for (int j = 0; j < n; j++) {
        sum += a[0][j];
    }

    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += a[i][j];
        }
        if (rowSum != sum) return false;
    }

    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += a[i][j];
        }
        if (colSum != sum) return false;
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        d1 += a[i][i];
        d2 += a[i][n - 1 - i];
    }

    return d1 == sum && d2 == sum;
}

//9 
void addMatrices(int a[][MAX], int b[][MAX], int res[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyByNumber(int a[][MAX], int res[][MAX], int rows, int cols, int k) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = a[i][j] * k;
        }
    }
}

//10
void multiplyMatrices(int a[][MAX], int b[][MAX], int res[][MAX],
                      int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

//11
void printSpiral(int a[][MAX], int rows, int cols) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            cout << a[top][j] << " ";
        top++;

        for (int i = top; i <= bottom; i++)
            cout << a[i][right] << " ";
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                cout << a[bottom][j] << " ";
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << a[i][left] << " ";
            left++;
        }
    }
}

//12
void rotateRight(int a[][MAX], int res[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][n - 1 - i] = a[i][j];
        }
    }
}
