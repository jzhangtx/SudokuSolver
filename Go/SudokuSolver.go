package main

import "fmt"

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func IsGood(sudoku [][]int, row, col int) bool {
	for c := 0; c < len(sudoku[0]); c++ {
		if col != c && sudoku[row][col] == sudoku[row][c] {
			return false
		}
	}

	for r := 0; r < len(sudoku); r++ {
		if r != row && sudoku[r][col] == sudoku[row][col] {
			return false
		}
	}

	for r := row / 3 * 3; r < (row/3+1)*3; r++ {
		for c := col / 3 * 3; c < (col/3+1)*3; c++ {
			if c != col && r != row && sudoku[row][col] == sudoku[r][c] { // the reason I use ||
				//  instead of && is
				//  the row and col had been
				//  checked (the above 2 blocks)
				return false
			}
		}
	}

	return true
}

func SolveSudoku(sudoku [][]int, row, col int) bool {
	if col == len(sudoku[0]) {
		row++
		col = 0
	}

	if row == len(sudoku) {
		return true
	}

	if sudoku[row][col] != 0 {
		return SolveSudoku(sudoku, row, col+1)
	}

	for i := 1; i <= 9; i++ {
		sudoku[row][col] = i
		if IsGood(sudoku, row, col) {
			if SolveSudoku(sudoku, row, col+1) {
				return true
			}
		}
	}

	return false
}

func SudokuSolver(sudoku [][]int) {
	SolveSudoku(sudoku, 0, 0)
}

func main() {
	for {
		fmt.Println("Please enter the sudoku to be resolved: ")
		sudoku := make([][]int, 9)
		for i := 0; i < 9; i++ {
			sudoku[i] = make([]int, 9)
			for j := 0; j < 9; j++ {
				fmt.Scan(&sudoku[i][j])
			}
		}

		SudokuSolver(sudoku)

		for _, s := range sudoku {
			for _, n := range s {
				fmt.Print(n, " ")
			}
			fmt.Println("")
		}
		fmt.Println("")

		fmt.Print("Continue (Y/N): ")
		var s string
		fmt.Scan(&s)
		if s == "y" || s == "Y" {
			break
		}
	}
}
