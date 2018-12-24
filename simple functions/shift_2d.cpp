#include <iostream>

using namespace std;


void shiftDown(int** matrix, int rows) {
	int* first = matrix[rows-1];
	for(int r = rows - 1; r > 0; r--) {
		matrix[r] = matrix[r-1];
	}
	matrix[0] = first;
}

void shiftRight(int** matrix, int rows, int cols) {
	for (int r = 0; r < rows; r++) {
		int first = matrix[r][cols-1];
		for (int c = cols-1; c > 0; c--) {
			matrix[r][c] = matrix[r][c-1];
		}
		matrix[r][0] = first;
	}
}

void dump(int** matrix, int rows, int cols) {
	for(int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			cout << matrix[r][c] << " ";
		}
		cout << endl;
	}
}

int main() {
	int rows, cols;
	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter cols: ";
	cin >> cols;

	int** matrix = new int*[rows];
	for (int r = 0; r < rows; r++) {
		matrix[r] = new int[cols];
	}

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			int element;
			cout << "Enter element " << r << "," << c << ": ";
			cin >> element;
			matrix[r][c] = element;
		}
	}

	dump(matrix, rows, cols);

	int mode, count;
	cout << "Enter mode (0 - right; 1 - down): ";
	cin >> mode;
	cout << "Enter shift count: ";
	cin >> count;

	if (mode == 0) {
		for (int i = 0; i < count; i++ ) {
			shiftRight(matrix, rows, cols);
		}
	}
	else if (mode == 1) {
		for (int i = 0; i < count; i++ ) {
			shiftDown(matrix, rows);
		}
	}
	else {
		cout << "invalid mode" << endl;
	}

	dump(matrix, rows, cols);
}

