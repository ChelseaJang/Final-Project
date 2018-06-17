#include <string>
#include <iostream>
#include "Sudoku.h"

int main() {
	std::cout << "Enter a sudoku puzzle to be solved in the following format:" << "\n"; // introduce sudoku format

	for (size_t row = 0; row < 9; ++row) { // cycle through the row values first (top to bottom)
		for (size_t col = 0; col < 9; ++col) { // cycle through column values of the respective row (right to left)
			std::cout << "0"; // print out value at current row and column
			std::cout << " "; // print spaces between the columns in each row
		}
		std::cout << "\n"; // start each row on a new line
	}
	std::cout << "\n"; // add a new row after each magic square printed

	std::cout << "Enter '0' for an empty square." << "\n" << "\n"; // set out rules for the numbers
	
	std::cout << "Enter sudoku puzzle to be solved:" << "\n"; // prompt user for square format
	std::vector<std::vector<int>> sudoku(9, std::vector<int>(9)); // initialize square
	std::cin >> sudoku; // read square format into Sudoku

	std::cin.get();
	std::cin.get();

	std::cout << "The sudoku puzzle you entered is:" << "\n";
	std::cout << sudoku << "\n";

	// solve magic square and print list of all solutions solutions
	solveSquare(sudoku, 0);

	std::cout << "Solving complete!" << "\n";
	std::cout << "There were " << counter(false) << " solutions!" << "\n"; // let user know how many solutions there were

	std::cin.get();
	std::cin.get();
	
	return 0;
}