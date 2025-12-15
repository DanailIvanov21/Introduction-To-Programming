#include <iostream>
using namespace std;

int* createArr(int n) {
	return new int[n];
}

int** createMatrix(int rows, int cols) {
	int** newMatrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		newMatrix[i] = createArr(cols);
	}
	return newMatrix;
}

void deleteMatrix(int** matrix, int rows) {
	
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
		cout << " deleted row" << i << endl;
	}
	
	delete[] matrix;
}


void read(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void print(const int *const*  matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}

}

int main() {

	int** m = createMatrix(3, 3);
	read(m, 3, 3);

	//

	print(m, 3, 3);
	deleteMatrix(m, 3);

}
