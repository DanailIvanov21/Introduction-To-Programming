#include <iostream>
//1
int main() {
    size_t N;
    std::cin >> N;

    int* arr = new int[N];
    for (size_t i = 0; i < N; i++)
        std::cin >> arr[i];

    for (int i = N - 1; i >= 0; i--)
        std::cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
//2
int* divisibleByK(const int* a, size_t n,const int* b, size_t m,int K, size_t& outSize)
{
    outSize = 0;

    for (size_t i = 0; i < n; i++)
        if (a[i] % K == 0) outSize++;

    for (size_t i = 0; i < m; i++)
        if (b[i] % K == 0) outSize++;


    int* res = new int[outSize];
    size_t idx = 0;
  
    for (size_t i = 0; i < n; i++)
        if (a[i] % K == 0) res[idx++] = a[i];

    for (size_t i = 0; i < m; i++)
        if (b[i] % K == 0) res[idx++] = b[i];

    return res;
}
//3
int* rotateRight(const int* arr, size_t n, size_t K) {
    if (n == 0) return nullptr;

    K %= n;
    int* res = new int[n];

    for (size_t i = 0; i < n; i++) {
        size_t newPos = (i + K) % n;
        res[newPos] = arr[i];
    }

    return res;
}
//4
int* divisibleByNeighbor(const int* arr, size_t n, size_t& outSize) {
    if (n < 2) {
      outSize = 0;
      return nullptr; 
    }

    outSize = 0;
    for (size_t i = 0; i < n; i++) {
        bool ok = false;

        if (i > 0 && arr[i] % arr[i-1] == 0) ok = true;
        if (i < n-1 && arr[i] % arr[i+1] == 0) ok = true;

        if (ok) outSize++;
    }

    int* res = new int[outSize];

    size_t idx = 0;
    for (size_t i = 0; i < n; i++) {
        bool ok = false;

        if (i > 0 && arr[i] % arr[i-1] == 0) ok = true;
        if (i < n-1 && arr[i] % arr[i+1] == 0) ok = true;

        if (ok) res[idx++] = arr[i];
    }

    return res;
}
//5
char* concatLowerUpper(const char* s1, const char* s2) {
    size_t count = 0;

    for (size_t i = 0; s1[i] != '\0'; i++)
        if (s1[i] >= 'a' && s1[i] <= 'z')
            count++;

    for (size_t i = 0; s2[i] != '\0'; i++)
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            count++;

    char* res = new char[count + 1];

    size_t idx = 0;

    for (size_t i = 0; s1[i] != '\0'; i++)
        if (s1[i] >= 'a' && s1[i] <= 'z')
            res[idx++] = s1[i];

    for (size_t i = 0; s2[i] != '\0'; i++)
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            res[idx++] = s2[i];

    res[idx] = '\0';
    return res;
}
//6
char* removeDuplicates(const char* s) {
    size_t n = 0;
    while (s[n] != '\0') n++;

    size_t count = 0;

    for (size_t i = 0; i < n; i++) {
        int freq = 0;

        for (size_t j = 0; j < n; j++) {
            if (s[i] == s[j])
                freq++;
        }

        if (freq == 1)
            count++;
    }

    char* res = new char[count + 1];

    size_t idx = 0;

    for (size_t i = 0; i < n; i++) {
        int freq = 0;

        for (size_t j = 0; j < n; j++) {
            if (s[i] == s[j])
                freq++;
        }

        if (freq == 1)
            res[idx++] = s[i];
    }

    res[idx] = '\0';
    return res;
}
//7
char* insertAtPositions(const char* s,const int* pos,size_t posCount,char S)
{
    size_t n = 0;
    while (s[n] != '\0')
        n++;
  
    char* res = new char[n + posCount + 1];

    size_t src = 0;  
    size_t dst = 0;   
    size_t p = 0;     

  
    while (src < n) {
        
        if (p < posCount && (int)src == pos[p]) {
            res[dst++] = S;
            p++;
        }

        res[dst++] = s[src++];
    }
    while (p < posCount) {
        res[dst++] = S;
        p++;
    }

    res[dst] = '\0';
    return res;
}
//8
char* firstLastWord(const char* s) {
     size_t n = 0;
    while (s[n] != '\0')
        n++;
    size_t start = 0;
    while (start < n && s[start] == ' ') start++;

    size_t end = start;
    while (end < n && s[end] != ' ') end++;

    size_t firstLen = end - start;

  
    size_t lastEnd = n;
    while (lastEnd > 0 && s[lastEnd-1] == ' ') lastEnd--;

    size_t lastStart = lastEnd;
    while (lastStart > 0 && s[lastStart-1] != ' ') lastStart--;

    size_t lastLen = lastEnd - lastStart;

    char* res = new char[firstLen + 1 + lastLen + 1];

    size_t idx = 0;
    for (size_t i = start; i < end; i++) res[idx++] = s[i];
    res[idx++] = ' ';
    for (size_t i = lastStart; i < lastEnd; i++) res[idx++] = s[i];

    res[idx] = '\0';
    return res;
}

//9
void splitUpperLower(const char* s, char*& X, char*& Y)
{
    size_t n = 0;
    while (s[n] != '\0')
        n++;

    
    size_t upperCount = 0;
    size_t lowerCount = 0;

    for (size_t i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            upperCount++;
        else if (s[i] >= 'a' && s[i] <= 'z')
            lowerCount++;
    }

  
    X = new char[upperCount + 1];
    Y = new char[lowerCount + 1];

  
    size_t ix = 0, iy = 0;

    for (size_t i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            X[ix++] = s[i];
        else if (s[i] >= 'a' && s[i] <= 'z')
            Y[iy++] = s[i];
    }

    X[ix] = '\0';
    Y[iy] = '\0';
}
//10
int* mergeSorted(const int* a, size_t n,
                 const int* b, size_t m,
                 size_t& outSize)
{
    outSize = n + m;
    int* res = new int[outSize];

    size_t i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) res[k++] = a[i++];
        else res[k++] = b[j++];
    }

    while (i < n) res[k++] = a[i++];
    while (j < m) res[k++] = b[j++];

    return res;
}


int main() {

    /* ЗАДАЧА 1 */
    {
        size_t N;
        std::cin >> N;

        int* arr = new int[N];
        for (size_t i = 0; i < N; i++)
            std::cin >> arr[i];

        for (int i = (int)N - 1; i >= 0; i--)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        delete[] arr;
    }

    /* ЗАДАЧА 2  */
    {
        size_t n = 4, m = 5;
        int* a = new int[n]{2, 4, 5, 8};
        int* b = new int[m]{3, 16, 7, 9, 10};

        size_t outSize;
        int* res = divisibleByK(a, n, b, m, 2, outSize);

        for (size_t i = 0; i < outSize; i++)
            std::cout << res[i] << " ";
        std::cout << "\n";

        delete[] a;
        delete[] b;
        delete[] res;
    }

    /* ЗАДАЧА 3  */
    {
        size_t n = 5;
        int* arr = new int[n]{1, 2, 3, 4, 5};

        int* r = rotateRight(arr, n, 2);

        for (size_t i = 0; i < n; i++)
            std::cout << r[i] << " ";
        std::cout << "\n";

        delete[] arr;
        delete[] r;
    }

    /* ЗАДАЧА 4 */
    {
        size_t n = 6;
        int* arr = new int[n]{5, 10, 20, 4, 2, 7};

        size_t outSize;
        int* res = divisibleByNeighbor(arr, n, outSize);

        for (size_t i = 0; i < outSize; i++)
            std::cout << res[i] << " ";
        std::cout << "\n";

        delete[] arr;
        delete[] res;
    }

    /* ЗАДАЧА 5* /
    {
        char* s1 = new char[8]{'a','b','c','A','G','H','p','\0'};
        char* s2 = new char[11]{'m','n','A','H','G','T','5','s','a','P','\0'};

        char* res = concatLowerUpper(s1, s2);
        std::cout << res << "\n";

        delete[] s1;
        delete[] s2;
        delete[] res;
    }

    /*  ЗАДАЧА 6  */
    {
        char* s = new char[17]{'a','k','l','a','h','k','3','g','*','5','g','g','k','k','k','s','\0'};

        char* res = removeDuplicates(s);
        std::cout << res << "\n";

        delete[] s;
        delete[] res;
    }

    /* ЗАДАЧА 7  */
    {
        char* s = new char[23]{'H','i',' ','h','e','r','e',' ','n','i','c','e',' ','o',' ','m','e','e',' ','y','o','u','.','\0'};
        int* pos = new int[3]{3, 13, 18};

        char* res = insertAtPositions(s, pos, 3, 't');
        std::cout << res << "\n";

        delete[] s;
        delete[] pos;
        delete[] res;
    }

    /* ЗАДАЧА 8 */
    {
        char* s = new char[13]{'H','e','l','l','o',' ','h','i',' ','h','e','y','\0'};

        char* res = firstLastWord(s);
        std::cout << res << "\n";

        delete[] s;
        delete[] res;
    }

    /* ЗАДАЧА 9 */
    {
        char* s = new char[22]{'I',' ','a','m',' ','t','h','e',' ','b','e','s','t',' ','P','l','a','y','e','r','!','\0'};

        char* X = nullptr;
        char* Y = nullptr;

        splitUpperLower(s, X, Y);

        std::cout << X << "\n";
        std::cout << Y << "\n";

        delete[] s;
        delete[] X;
        delete[] Y;
    }

    /* ЗАДАЧА 10 */
    {
        size_t n = 5, m = 4;
        int* a = new int[n]{1, 3, 5, 10, 21};
        int* b = new int[m]{2, 7, 12, 32};

        size_t outSize;
        int* res = mergeSorted(a, n, b, m, outSize);

        for (size_t i = 0; i < outSize; i++)
            std::cout << res[i] << " ";
        std::cout << "\n";

        delete[] a;
        delete[] b;
        delete[] res;
    }

    return 0;
}
