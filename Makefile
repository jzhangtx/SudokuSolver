SudokuSolver: SudokuSolver.o
	g++ -g -o SudokuSolver.exe SudokuSolver.o -pthread    

SudokuSolver.o: SudokuSolver/SudokuSolver.cpp
	g++ -g  -c -pthread SudokuSolver/SudokuSolver.cpp
