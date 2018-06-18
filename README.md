# Final-Project - Sudoku Puzzle

Repository for final project

**Some introductions to Sudoku:**

https://en.wikipedia.org/wiki/Sudoku

* There are different kinds of Sudoku puzzles
* **Some variations:**
    - Different grid sizes
    - Faces with three different mouths and head shapes
    - Uses of symbols instead of 1-9 to make filling out the puzzle more challenging
    - Strange grid shapes (not classical box)

* **Main concepts:**
    - Fill out grids without repeating
    - Don't break rules about repetition

* **Classical Sudoku**
    - 9 grids with 9 spots each
    - Fill boxes from 1-9
    - Fill columns from 1-9
    - Fill rows from 1-9
    - No repetition of numbers within the box, row, or column
  
* **Mathematics of (Classical) Sudoku**
    - A complete sudoku is a special type of latin square
    - The fewest number of clues possible for a proper sudoku is 17
    - Sudokus with 18 clues and rotational symmetry have been found
    - The maximum number of clues that can be provided while still not rendering a unique solution is four short of a full grid (77)
    - The number of classic 9×9 Sudoku solution grids is 6,670,903,752,021,072,936,960

**Suggested algorithms for solving sudoku:**
  * https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Sudoku_brute_force
  * https://en.wikipedia.org/wiki/Dancing_Links

I wrote code to solve the sudoku puzzle with no GUI using Visual Studios. This code is in the "Sudoku Console without GUI" file. The code was solved using the brute force method where it starts from the beginning and just tries to solve by plugging in every number possible and backtracking when it runs into an issue. This is done through recursion and by passing by value. This is memory intensive but is the best way I could think of to continue with the code at the time.

The next goal is to implement the sudoku solver with a user interface to make it feel more comfortable for the user instead of having the user try to enter the values by hand with many chances of mesesing up.


**Website for formatting text in read.me files:**
https://help.github.com/articles/basic-writing-and-formatting-syntax/

*Documentation for the QGridLayout Class:*
http://doc.qt.io/qt-5/qgridlayout.html

*Documentation for the QFormLayout Class:*
http://doc.qt.io/archives/qt-4.8/qformlayout.html

*Documentation of the QVector Class:*
http://doc.qt.io/qt-5/qvector.html

*Documentation of the QSpinBox Class:*
http://doc.qt.io/qt-5/qspinbox.html

*Documentation of the QPushButton Class:*
http://doc.qt.io/qt-5/qpushbutton.html

