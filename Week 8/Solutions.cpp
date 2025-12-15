//1
bool isEven(unsigned int x) {
    return (x & 1) == 0;
}

//2
unsigned int powerOfTwo(int k) {
    return 1 << k;
}

//3
int checkBit(unsigned int a, unsigned int pos) {
    return (a >> pos) & 1;
}

//4
int clearBit(int a, int pos) {
    return a & ~(1 << pos);
}

//5
int makeBitOne(int a, int pos) {
    return a | (1 << pos);
}

//6
int toggleBit(int a, int pos) {
    return a ^ (1 << pos);
}

//7
int setBit(int a, int pos, int value) {
    if (value == 1)
        return makeBitOne(a, pos);
    else
        return clearBit(a, pos);
}

//8
int flipRightmost1(int a) {
    return a ^ (a & (-a));
}

//8
int flipLeftmost0(int a) {
    int mask = 1 << 30;

    while (mask > 0 && (a & mask))
        mask >>= 1;

    return a ^ mask;
}

//9
void swapNoTemp(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//10,11
int countOnes(int x) {
    int count = 0;

    while (x > 0) {
        if (x & 1)
            count++;
        x >>= 1;
    }

    return count;
}

bool arePermutations(int a, int b) {
    return countOnes(a) == countOnes(b);
}

//бонус 1
int findUnique(const int* arr, int n) {
    int result = 0;

    for (int i = 0; i < n; i++)
        result ^= arr[i];

    return result;
}

//бонус2
void printSubsets(const int* arr, int n) {
    int total = 1 << n;

    for (int mask = 0; mask < total; mask++) {
        cout << "[";

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                cout << arr[i] << " ";
        }

        cout << "]\n";
    }
}
