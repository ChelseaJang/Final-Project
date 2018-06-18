# Final-Project - Sudoku Puzzle

Repository for final project

## **Some introductions to Sudoku:**

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


## My Coding Process for First Part (done with Visual Studios 2017)
I wrote code to solve the sudoku puzzle with no GUI using Visual Studios. This code is in the "Sudoku Console without GUI" file. The code was solved using the brute force method where it starts from the beginning and just tries to solve by plugging in every number possible and backtracking when it runs into an issue. This is done through recursion and by passing by value. This is memory intensive but is the best way I could think of to continue with the code at the time.

The next goal is to implement the sudoku solver with a user interface to make it feel more comfortable for the user instead of having the user try to enter the values by hand with many chances of mesesing up.

## Helpful Websites for Using Qt Creator (I'm using Version 4.6.0):


**Documentation for the QGridLayout Class:**
  - http://doc.qt.io/qt-5/qgridlayout.html

**Documentation for the QFormLayout Class:**
  - http://doc.qt.io/archives/qt-4.8/qformlayout.html

**Documentation of the QVector Class:**
  - http://doc.qt.io/qt-5/qvector.html

**Documentation of the QSpinBox Class:**
  - http://doc.qt.io/qt-5/qspinbox.html

**Documentation of the QPushButton Class:**
  - http://doc.qt.io/qt-5/qpushbutton.html
  
**Documentation of Signals and Slots in Q**
  - http://doc.qt.io/qt-5/signalsandslots.html
  
**First video in a series of useful videos on using Qt Creator**
  - https://www.youtube.com/watch?v=EkjaiDsiM-Q

**Suggestion for accessing items at a certain position on a QFormLayout class object:**
  - https://stackoverflow.com/questions/25574802/qt-qgridlayout-access-element-at-coordinates


## My Coding Process for Second Part (done with Qt Creator 4.6.0)
I wrote code to solve the sudoku puzzle with a GUI using Qt Creator. This code is in the "Sudoku with GUI" file. The code was solved using the brute force method where it starts from the beginning and just tries to solve by plugging in every number possible and backtracking when it runs into an issue. It is basically the code from the first part with a GUI added.

There are some issues. For example, pressing the "Show Answer" button leads to the loss of entered data if the "Solve Puzzle" hasn't been solved. I would like to solve this in the future. Furthermore, the process is too memory intensive. Thus, leaving the board as all zeros and pushing "Solve Puzzle" makes the program crash. This would also need to be fixed in the future.

I enjoyed how I was able to display several answers in the console version (from the first part). It was very disappointed that I was unable to figure out how to do it in this part. I would like to try to implement it in the future. Then, in cases where multiple solutions are possible, I would be able to display the different solutions sequentitially as well as display the number of solutions that exist (as well as whether there ***are*** any solutions).

**Some Websites that helped me in this process:**
  * website I used to generate sudoku puzzles that I plugged into my own widget during debugging:
    - https://www.websudoku.com/
  * website that I was trying (and failed) to imitate:
    - https://www.sudoku-solutions.com/
    
**A website/idea that may be useful/interesting to try out in the future:**

https://doc.qt.io/archives/qq/qq10-signalmapper.html

## Miscellaneous Helful Links
**Website for formatting text in read.me files:**
  * https://help.github.com/articles/basic-writing-and-formatting-syntax/

**Website for vector class:**
  * http://www.cplusplus.com/reference/vector/vector/
