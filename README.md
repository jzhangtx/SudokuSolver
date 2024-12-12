Sudoku Solver


You are given 9 X 9 sudoku board where some cells are filled. You need to solve the sudoku.

A correctly solved sudoku has the following properties:

Each row must contain all integers from 1 to 9.
Each column must contain all integers from 1 to 9.
Each of the nine 3 X 3 sub-boxes must contain all integers from 1 to 9.
Testing
Input Format
The first line contains an integer ‘T’, denoting the number of test cases.

For each test case, there are 9 lines, each containing 9 space-separated digits (0-9) denoting values in the cell. An empty cell is represented by '.'.

Output Format
For each test case, a line containing 1 or 0 depending on whether the sudoku is valid on not respectively.

Sample Input
1
2 5 . . . 3 . . .
. . . . . . 2 7 .
8 7 . . . 6 4 . .
. 2 . . . 8 1 9 3
. 1 5 . 4 . 8 . .
. . . 1 . . . . 4
. . . 7 3 4 . . .
. . . 6 . . . . 9
. 6 4 . . 9 . 5 8
Expected Output
2 5 6 4 7 3 9 8 1
3 4 9 8 5 1 2 7 6
8 7 1 9 2 6 4 3 5
4 2 7 5 6 8 1 9 3
9 1 5 3 4 2 8 6 7
6 8 3 1 9 7 5 2 4
5 9 8 7 3 4 6 1 2
1 3 2 6 8 5 7 4 9
7 6 4 2 1 9 3 5 8