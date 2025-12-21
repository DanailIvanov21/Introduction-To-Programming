// Ползваме готовите фунцкии от example.cpp за int масиви
// и ще изпозваме и новите готови фунцкии за char масиви преди
// решенията на задачите

int strLen(const char* s) {
    int n = 0;
    while (s && s[n]) n++;
    return n;
}

char* copyStr(const char* s) {
    int n = strLen(s);
    char* r = new char[n + 1];
    for (int i = 0; i < n; i++) r[i] = s[i];
    r[n] = '\0';
    return r;
}

bool isPalindrome(const char* s, int n) {
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i]) return false;
    return true;
}

void deleteStringArray(char** arr, int count) {
    for (int i = 0; i < count; i++) delete[] arr[i];
    delete[] arr;
}

void printStringArray(char** arr, int count) {
    for (int i = 0; i < count; i++) cout << arr[i] << "\n";
}

char** createCharMatrix(int rows, int cols) {
    char** m = new char*[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new char[cols];
    }
    return m;
}

void deleteCharMatrix(char** m, int rows) {
    for (int i = 0; i < rows; i++) delete[] m[i];
    delete[] m;
}

void printCharMatrix(char** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << m[i][j];
        cout << "\n";
    }
}
char* copyFixedLenAsCStr(const char* src, int len) {
    char* res = new char[len + 1];
    for (int i = 0; i < len; i++) {
        res[i] = src[i];
    }
    res[len] = '\0';
    return res;
}
//1
int** removeRow(const int* const* m, int rows, int cols, int idxRow) {
    if (rows <= 0 || cols <= 0) return nullptr;
    if (idxRow < 0 || idxRow >= rows) return nullptr;
    if (rows == 1) return nullptr;

    int** res = createMatrix(rows - 1, cols);

    int r = 0;
    for (int i = 0; i < rows; i++) {
        if (i == idxRow) continue;
        for (int j = 0; j < cols; j++) res[r][j] = m[i][j];
        r++;
    }
    return res;
}


//2
int** removeCol(const int* const* m, int rows, int cols, int idxCol) {
    if (rows <= 0 || cols <= 0) return nullptr;
    if (idxCol < 0 || idxCol >= cols) return nullptr;
    if (cols == 1) return nullptr;

    int** res = createMatrix(rows, cols - 1);

    for (int i = 0; i < rows; i++) {
        int c = 0;
        for (int j = 0; j < cols; j++) {
            if (j == idxCol) continue;
            res[i][c++] = m[i][j];
        }
    }
    return res;

//3
int** transposeMatrix(const int* const* m, int rows, int cols) {
    if (rows <= 0 || cols <= 0) return nullptr;

    int** t = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t[j][i] = m[i][j];

    return t;
}

//4
void splitOddEven(
    const int* const* m, int rows, int cols,
    int**& odd, int& oddRows, int& oddCols,
    int**& even, int& evenRows, int& evenCols
) {
    odd = nullptr;
    even = nullptr;

    if (cols > rows) {
        //разделяме по КОЛОНИ 
        oddCols  = cols / 2;          // 1,3,5,...
        evenCols = (cols + 1) / 2;    // 0,2,4,...

        oddRows = evenRows = rows;

        if (oddCols > 0) odd = createMatrix(rows, oddCols);
        even = createMatrix(rows, evenCols);

        for (int i = 0; i < rows; i++) {
            int o = 0, e = 0;
            for (int j = 0; j < cols; j++) {
                if (j % 2 == 0)
                    even[i][e++] = m[i][j];
                else
                    odd[i][o++] = m[i][j];
            }
        }
    } else {
        // разделяме по РЕДОВЕ 
        oddRows  = rows / 2;          // 1,3,5,...
        evenRows = (rows + 1) / 2;    // 0,2,4,...

        oddCols = evenCols = cols;

        if (oddRows > 0) odd = createMatrix(oddRows, cols);
        even = createMatrix(evenRows, cols);

        int o = 0, e = 0;
        for (int i = 0; i < rows; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < cols; j++)
                    even[e][j] = m[i][j];
                e++;
            } else {
                for (int j = 0; j < cols; j++)
                    odd[o][j] = m[i][j];
                o++;
            }
        }
    }
}
     
//5
char** findPalindromesEasy(char** m, int N, int& count) {
    count = 0;
    char** res = new char*[2 * N + 2];

    char* temp = new char[N];

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) temp[j] = m[i][j];
        if (isPalindrome(temp, N)) {
            res[count++] = copyFixedLenAsCStr(temp, N);
        }
    }

    
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) temp[i] = m[i][j];
        if (isPalindrome(temp, N)) {
            res[count++] = copyFixedLenAsCStr(temp, N);
        }
    }

    
    for (int i = 0; i < N; i++) temp[i] = m[i][i];
    if (isPalindrome(temp, N)) {
        res[count++] = copyFixedLenAsCStr(temp, N);
    }

    
    for (int i = 0; i < N; i++) temp[i] = m[i][N - 1 - i];
    if (isPalindrome(temp, N)) {
        res[count++] = copyFixedLenAsCStr(temp, N);
    }

    delete[] temp;
    return res;
}

//6

//7
//8