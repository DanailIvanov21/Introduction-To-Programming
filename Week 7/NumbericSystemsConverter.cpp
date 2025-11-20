#include <iostream>
using namespace std;

const int SIZE = 100;

int countDigitsInKSystem(int num, int k) {
	int counter = 0;
	while (num > 0)
	{
		counter++;
		num /= k;
	}
	return counter;
}

char getCharFromValue(int n) {
	if (n >= 0 && n <= 9) {
		return '0' + n;
	}
	return n + 'A' - 10;
}

int getValueFromChar(char ch) {
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	}
	return ch - 'A' + 10;
}

int fromKto10(char kSystem[], int kArrSize, int k) {
	int result = 0;
	for (int i = kArrSize - 1, exponent = 1; i >= 0 ; i--, exponent *= k)
	{
		result += getValueFromChar(kSystem[i]) * exponent;
	}
	return result;
}

void from10toN(int num, char result[], int& nArrSize, int n) {
	nArrSize = countDigitsInKSystem(num, n);
	for (long long i = nArrSize - 1; i >= 0; i--)
	{
		result[i] = getCharFromValue(num % n);
		num /= n;
	}
}

void fromKtoN(char kSystem[], int kSize, int k, char nSystem[], int& nSize, int n) { //defined with convertions between 2 and 36 counting systems
	from10toN(fromKto10(kSystem, kSize, k), nSystem, nSize, n);
}

int main()
{
	char arr[] = { 'A', 'B', 'C' };
	int sizeArr = 0;
	char result[SIZE];
	fromKtoN(arr, 3, 13, result, sizeArr, 10);
	for (size_t i = 0; i < sizeArr; i++)
	{
		std::cout << result[i];
	}
}
