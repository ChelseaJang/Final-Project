#include "Sudoku.h"

std::istream& operator>>(std::istream& in, std::vector<std::vector<int>>& square) {
	for (size_t row = 0; row < square.size(); ++row) { // cycle through row values first (top to bottom)
		for (size_t col = 0; col < square.size(); ++col) { // cycle through column values of the respective row (right to left)
			in >> square[row][col]; // input value into current row and column

									// if fails, default value is 0 (indicates empty)
			if (in.fail()) { // if the streams is in a failed state, including when the position is empty
				in.clear(); // clear stream
				in.ignore();
			}
		}
	}
	return in; // return istream in
}

std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<int>>& square) {
	for (size_t row = 0; row < square.size(); ++row) { // cycle through the row values first (top to bottom)
		for (size_t col = 0; col < square.size(); ++col) { // cycle through column values of the respective row (right to left)
			out << square[row][col]; // print out value at current row and column
			out << " "; // print spaces between the columns in each row
		}
		out << "\n"; // start each row on a new line
	}
	out << "\n"; // add a new row after each magic square printed
	return out; // return ostream out
}

size_t counter(bool increase) {
	static size_t count = 0; // initialized to 0 only once
	if (increase) { // if should increase
		++count; // then increase
	}
	return count; // return current number of solutions found
}

bool empty(size_t row, size_t col, const std::vector<std::vector<int>>& check) {
	return check[row][col] == 0; // is empty if equals 0, default value when a vector is constructed
}

////////////////////////////////////UPDATE IN HEADER FILE
bool taken(int i, size_t row_1, size_t col_1, const std::vector<std::vector<int>>& check) {
	//check grid of nine
	//int box = grid(row_1, col_1); //remove???
	/*
	beginning of box:
	row: (box/3+1)
	col: (box%3)*3-1
	
	*/
	//int boxRow = row_1 / 3;
	//int boxCol = col_1 / 3;
	for (size_t row = 0; row < 3; ++row) { // cycle through the rows first
		for (size_t col = 0; col < 3; ++col) { // cycle through column values of the respective row
			if (check[(row_1 / 3) * 3 + row][(col_1 / 3) * 3 + col] == i) { // if the number we are checking has already been used
				return true; // return true, since it has already been used
			}
		}
	}

	//check column
	for (size_t row = 0; row < 9; ++row) { // cycle through the rows first
		if (check[row][col_1] == i) { // if the number we are checking has already been used
			return true; // return true, since it has already been used

		}
	}

	//check row
	for (size_t col = 0; col < 9; ++col) { // cycle through the rows first
		if (check[row_1][col] == i) { // if the number we are checking has already been used
			return true; // return true, since it has already been used

		}
	}


	return false; // number hasn't been used in check, return false
}

bool checkValid(const std::vector<std::vector<int>>& check) {
	size_t size = check.size();
	int solutionSum = (size*(size*size + 1)) / 2; // the sums of the rows, columns and diagonals of valid magic square is n(n^2 +1)/2
	int sum = 0; // use to calculate the sums of the rows, columns, and diagonals

				 // check sums of the rows
	for (size_t row = 0; row < size; ++row) { // cycle through the rows first
		sum = 0; // clear sum before calculating the sum of each row

		for (size_t col = 0; col < size; ++col) { // cycle through the columns of the respective row
			sum += check[row][col]; // add the values in the row into sum to get the sum of the respective row
		}
		if (sum != solutionSum) { // if the row has the wrong sum
			return false; // the square is not a valid solution
		}
	}

	//check sums of the columns
	for (size_t col = 0; col < size; ++col) { // cycle through the columns first
		sum = 0; // clear sum before calculating the sum of each column

		for (size_t row = 0; row < size; ++row) { // cycle through the row of the respective column
			sum += check[row][col]; // add the values in the column into sum to get the sum of the respective column
		}
		if (sum != solutionSum) { // if the column has the wrong sum
			return false; // the square is not a valid solution
		}
	}

	//check upper left to lower right diagonal
	sum = 0; // clear sum before calculating the sum of the diagonal
	for (size_t row = 0; row < size; ++row) { // cycle through the rows
		sum += check[row][row]; // add the values in position (n,n) into sum to get the sum of the diagonal
	}
	if (sum != solutionSum) { // if the diagonal has the wrong sum
		return false; // the square is not a valid solution
	}

	//check upper right to lower left diagonal
	sum = 0; // clear sum before calculating the sum of the diagonal
	for (size_t row = 0; row < size; ++row) { // cycle through the rows
		sum += check[row][size - (row + 1)]; // add the values in position (n, size-n) into sum to get sum of the diagonal
	}
	if (sum != solutionSum) { // if the diagonal has the wrong sum
		return false; // the square is not a valid solution
	}

	return true; // if square has passed all of the above tests, it is a valid solution
}

void solveSquare(std::vector<std::vector<int>> square, size_t position) {
	//size_t size = square.size(); // size of square
	size_t row = position / 9; // row of current position
	size_t col = position % 9; // column of current position

	if (position == 9 * 9) { // have finished filling in square
		//if (checkValid(square)) { // if the square is a valid solution
			counter(true); // increase the solution count
			std::cout << square; // print the solution square
		//}
	}
	else if (empty(row, col, square)) { // the current position is empty
		for (int i = 1; i <= 9; ++i) { // loop through the possible numbers, i, to put in the square
			if (!taken(i, row, col, square)) { // if number i has not been used in the square
				square[row][col] = i; // put number i in the square at given position

				//std::cout << square;


				solveSquare(square, position + 1); // call solveSquare on the next position, creating a copy of square in the process
			}
		}
	}
	else { // the current position is not empty
		solveSquare(square, position + 1); // call solveSquare on the next position, creating a copy of square in the process
	}
}