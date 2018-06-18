#include "sudokusolver.h"
#include "ui_sudokusolver.h"

SudokuSolver::SudokuSolver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuSolver),
    sudoku(9, std::vector<int>(9, 0)),
    answer(9, std::vector<int>(9, 0))
{
    ui->setupUi(this);

    connect(ui->solveButton, SIGNAL(pressed()), this, SLOT(solveSudoku()));
    // connect(ui->solveButton, SIGNAL(pressed()), ui->displayAnswersButton, SLOT(setEnabled(bool)));

    connect(ui->eraseButton, SIGNAL(pressed()), this, SLOT(clearBoard()));
    // connect(ui->eraseButton, SIGNAL(pressed()), ui->displayAnswersButton, SLOT(setDisabled(bool)));


    connect(ui->displayAnswersButton, SIGNAL(toggled(bool)), this, SLOT(displayAnswer()));
}

SudokuSolver::~SudokuSolver()
{
    delete ui;
}

void SudokuSolver::solveSudoku(){
    for (size_t row = 0; row<9; ++row){
        for(size_t col = 0; col <9; ++col){
            QLayoutItem* item = ui->SudokuBoard->itemAtPosition(row, col);
            QWidget* widget = item->widget();
            QSpinBox* spinBox = dynamic_cast<QSpinBox*>(widget);

            sudoku[row][col] = spinBox->value();
        }
    }

    solveSquare(sudoku, 0);

}

void SudokuSolver::solveSquare(std::vector<std::vector<int>>& square, size_t position) {
    size_t row = position / 9; // row of current position
    size_t col = position % 9; // column of current position

    if (position == 9 * 9) { // have finished filling in square
        for (size_t row = 0; row<9; ++row){
            for(size_t col = 0; col <9; ++col){
                answer[row][col] = square[row][col];
            }
        }
    }
    else if (empty(row, col, square)) { // the current position is empty
        for (int i = 1; i <= 9; ++i) { // loop through the possible numbers, i, to put in the square
            if (!taken(i, row, col, square)) { // if number i has not been used in the square
                square[row][col] = i; // put number i in the square at given position
                solveSquare(square, position + 1); // call solveSquare on the next position, creating a copy of square in the process
            }
            square[row][col] = 0;
        }
    }
    else { // the current position is not empty
        solveSquare(square, position + 1); // call solveSquare on the next position, creating a copy of square in the process
    }
}

// slot used to let class know to clear the sudoku board
void SudokuSolver::clearBoard(){
    for (size_t row = 0; row<9; row++){
        for(size_t col = 0; col <9; col++){
            QLayoutItem* item = ui->SudokuBoard->itemAtPosition(row, col);
            QWidget* widget = item->widget();
            QSpinBox* spinBox = dynamic_cast<QSpinBox*>(widget);
            spinBox->setValue(0);

            sudoku[row][col] = 0;
            answer[row][col] = 0;
        }
    }
}

// check if input has been put into vector sudoku
bool SudokuSolver::notEntered(){
    for (size_t row = 0; row<9; row++){
        for(size_t col = 0; col <9; col++){
            QLayoutItem* item = ui->SudokuBoard->itemAtPosition(row, col);
            QWidget* widget = item->widget();
            QSpinBox* spinBox = dynamic_cast<QSpinBox*>(widget);
            if(sudoku[row][col] != spinBox->value()){
                return true;
            }
        }
    }
    return false;
}

void SudokuSolver::displayAnswer(){
    if(ui->displayAnswersButton->isChecked()){
        ui->displayAnswersButton->setText("Display Starting Board");
        display(answer);
    }
    else{
        ui->displayAnswersButton->setText("Display Answer");
        display(sudoku);
    }
}

void SudokuSolver::display(const std::vector<std::vector<int>>& toDisplay){
    for (size_t row = 0; row<9; ++row){
        for(size_t col = 0; col <9; ++col){
            QLayoutItem* item = ui->SudokuBoard->itemAtPosition(row, col);
            QWidget* widget = item->widget();
            QSpinBox* spinBox = dynamic_cast<QSpinBox*>(widget);

            spinBox->setValue(toDisplay[row][col]);
        }
    }
}

// functions for solving the sudoku board

bool SudokuSolver::empty(size_t row, size_t col, const std::vector<std::vector<int>>& check) {
    return check[row][col] == 0; // is empty if equals 0, default value when a vector is constructed
}

bool SudokuSolver::taken(int i, size_t row_1, size_t col_1, const std::vector<std::vector<int>>& check) {
    //check grid of nine
    /*
    beginning of subbox (of 9 values):
    row: (box/3+1)
    col: (box%3)*3-1
    */
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
