#ifndef ___MAGIC_SQUARE_SUDOKU___
#define ___MAGIC_SQUARE_SUDOKU___


#include <vector>
#include <iostream>


/**
operator>> reads from a stream into a magic square of type std::vector<std::vector<int>>
on the right'hand side of an input-stream to format the magic square
@param in istream object used to read the double values
@param square the vector<vector<int>> object modified by the input stream, used to format magic square
@return istream in
*/
std::istream& operator>>(std::istream& in, std::vector<std::vector<int>>& square);

/**
operator<< prints/displays the complex number with an output stream
@param out ostream object used to print/display the complex number
@param square the vector<vector<int>> object to be printed/displayed
@return ostream out
*/
std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<int>>& square);

/**
counter increments a count that tracks the number of solutions found when told to and returns its count value
@param increase whether or not to increment the counter
@return the count value
*/
size_t counter(bool increase);

/**
empty checks if a given position in the magic square is empty
@param row the row value of the position being checked
@param col the column value of the position being checked
@param check the magic square of type vector<vector<int>> the check is performed on
@return whether the given position of magic square check is empty: true if it is empty (value = 0), false otherwise
*/
bool empty(size_t row, size_t col, const std::vector<std::vector<int>>& check);

/**
taken checks if a given number is already used in the magic square
@param i the number being checked
@param check the magic square of type vector<vector<int>> the check is performed on
@return whether the given number has already been used in the magic square: true is it has been used, false otherwise
*/
bool taken(int i, size_t row_1, size_t col_1, const std::vector<std::vector<int>>& check);

/**
checkValid checks if a complete magic square satisfied the proper conditions to a be a solution
@param check the magic square of type vector<vector<int>> the check is performed on
@return whether the magic square satisfies the proper conditions to be a solution: true if it satisfies the conditions, false otherwise
*/
bool checkValid(const std::vector<std::vector<int>>& check);

//recursive function solveSquare that accepts a std::vector<std::vector<int>> and an index tracking the number of slots already considered in the recursion
/**
solveSquare accepts a std::vector<std::vector<int>> and an index tracking the number of slots already considered to solve the magic square through recursion
and prints the solutions as well as counts the numbers of solutions found
@param square
@param position
*/
void solveSquare(std::vector<std::vector<int>> square, size_t position);


#endif // "MagicSquare.h"