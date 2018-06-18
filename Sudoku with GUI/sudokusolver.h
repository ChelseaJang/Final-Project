#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class SudokuSolver;
}

class SudokuSolver : public QMainWindow
{
    Q_OBJECT

public:
    explicit SudokuSolver(QWidget *parent = 0);
    ~SudokuSolver();


public slots:
    void solveSudoku();
    void clearBoard();
    void displayAnswer();

private:
    // member variables
    Ui::SudokuSolver *ui;
    std::vector<std::vector<int>> sudoku;
    std::vector<std::vector<int>> answer;

    // member functions
    void solveSquare(std::vector<std::vector<int>>& square, size_t position);
    bool notEntered();
    void display(const std::vector<std::vector<int>>& toDisplay);
    bool empty(size_t row, size_t col, const std::vector<std::vector<int>>& check);
    bool taken(int i, size_t row_1, size_t col_1, const std::vector<std::vector<int>>& check);
};

#endif // SUDOKUSOLVER_H
