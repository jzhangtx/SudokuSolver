// SudokuSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

bool Safe(std::vector<std::vector<int>>& sudoku, int row, int col)
{
    // Check the column
    for (size_t i = 0; i < 9; ++i)
        if (row != i && sudoku[i][col] == sudoku[row][col])
            return false;

    // Check the row
    for (size_t i = 0; i < 9; ++i)
        if (col != i && sudoku[row][i] == sudoku[row][col])
            return false;

    // Check the 3*3 square. row/3*3 is the top of the square
    //  col/3*3 is the left of the square
    for (size_t i = row / 3 * 3; i < (row / 3 + 1) * 3; ++i)
    {
        for (size_t j = col / 3 * 3; j < (col / 3 + 1) * 3; ++j)
        {
            if ((i != row || j != col) && sudoku[row][col] == sudoku[i][j])
                return false;
        }
    }

    return true;
}

bool Sudoku(std::vector<std::vector<int>>& sudoku, int row, int col)
{
    if (row == 8 && col == 9)
        return true;

    if (col == 9)
    {
        row++;
        col = 0;
    }

    if (sudoku[row][col] != 0)
        return Sudoku(sudoku, row, ++col);

    for (int i = 1; i <= 9; ++i)
    {
        sudoku[row][col] = i;
        if (Safe(sudoku, row, col) && Sudoku(sudoku, row, col + 1))
            return true;
        sudoku[row][col] = 0;
    }

    return false;
}

void SudokuSolver(std::vector<std::vector<int>>& sudoku)
{
    Sudoku(sudoku, 0, 0);
}

int main()
{
    std::vector<std::vector<int>> sudoku{
        {2, 5, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 7, 0},
        {8, 7, 0, 0, 0, 6, 4, 0, 0},
        {0, 2, 0, 0, 0, 8, 1, 9, 3},
        {0, 1, 5, 0, 4, 0, 8, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 4},
        {0, 0, 0, 7, 3, 4, 0, 0, 0},
        {0, 0, 0, 6, 0, 0, 0, 0, 9},
        {0, 6, 4, 0, 0, 9, 0, 5, 8}
    };
    SudokuSolver(sudoku);
    for (auto& row : sudoku)
    {
        for (auto col : row)
            std::cout << col << " ";
        std::cout << std::endl;
    }
}
