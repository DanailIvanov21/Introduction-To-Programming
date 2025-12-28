//За решението на задачите използваме написаните алгоритми
// от https://github.com/DanailIvanov21/Introduction-To-Programming/blob/main/Week12/example.cpp

//1
bool findInMatrix(int** matrix, int rows, int cols, int value,
                  int& foundRow, int& foundCol)
{
    for (int row = 0; row < rows; row++) {
        int col = binarySearch(matrix[row], 0, cols - 1, value);
        if (col != -1) {
            foundRow = row;
            foundCol = col;
            return true;
        }
    }
    return false;
}

//2
int insertIndex(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    int position = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= x) {
            position = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return position;
}

//3
int longestEqualSequence(int arr[], int n)
{
    int maxLen = 1;
    int currentLen = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentLen++;
            if (currentLen > maxLen)
                maxLen = currentLen;
        } else {
            currentLen = 1;
        }
    }
    return maxLen;
}

//4
int firstMissing(int arr[], int n)
{
    selectionSort(arr, n);

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1] + 1) {
            return arr[i - 1] + 1;
        }
    }
    return -1; 
}

//5
int kthLargest(int arr[], int n, int k)
{
    for (int i = 0; i < k; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        swap(arr[i], arr[maxIndex]);
    }
    return arr[k - 1];
}

//6
int maxCandies(int prices[], int n, int money)
{
    insertionSort(prices, n);

    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (sum + prices[i] > money)
            break;
        sum += prices[i];
        count++;
    }
    return count;
}

//7
void evenOddSort(int numbers[], int size)
{
    int evenNumbers[100];
    int oddNumbers[100];

    int evenCount = 0;
    int oddCount = 0;

    for (int index = 0; index < size; index++) {
        if (numbers[index] % 2 == 0) {
            evenNumbers[evenCount++] = numbers[index];
        } else {
            oddNumbers[oddCount++] = numbers[index];
        }
    }

    bubbleSort(evenNumbers, evenCount); 
    bubbleSort(oddNumbers, oddCount);  

    int writeIndex = 0;

    for (int i = 0; i < evenCount; i++) {
        numbers[writeIndex++] = evenNumbers[i];
    }

    for (int i = oddCount - 1; i >= 0; i--) {
        numbers[writeIndex++] = oddNumbers[i];
    }
}

//8
void pairGuests(int heights[], int count)
{
    int boysHeights[100];
    int girlsHeights[100];

    int boysCount = 0;
    int girlsCount = 0;

    for (int i = 0; i < count; i++) {
        if (heights[i] % 2 == 1) {
            boysHeights[boysCount++] = heights[i];
        } else {
            girlsHeights[girlsCount++] = heights[i];
        }
    }

    insertionSort(boysHeights, boysCount);
    insertionSort(girlsHeights, girlsCount);

    for (int i = 0; i < boysCount; i++) {
        cout << boysHeights[i] << " " << girlsHeights[i] << endl;
    }
}

//9
void mergeSortedArrays(int arr1[], int n1,
                       int arr2[], int n2,
                       int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            result[k++] = arr1[i++];
        else
            result[k++] = arr2[j++];
    }

    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
}

//10
void unionUnsorted(int arr1[], int n1,
                   int arr2[], int n2,
                   int result[], int& size)
{
    size = 0;
    for (int i = 0; i < n1; i++)
        result[size++] = arr1[i];
    for (int i = 0; i < n2; i++)
        result[size++] = arr2[i];

    insertionSort(result, size);
}

//11
void intersection(int arr1[], int n1,
                  int arr2[], int n2,
                  int result[], int& size)
{
    insertionSort(arr1, n1);
    insertionSort(arr2, n2);

    int i = 0, j = 0;
    size = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] == arr2[j]) {
            result[size++] = arr1[i];
            i++; j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
}
//8
