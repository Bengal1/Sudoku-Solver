# Sudoku-Solver

This is a simple implenemtation of *Sudoku Solving Algorithm*. The program is given a start sudoku grid and by using a method based on imprived *Backtracking Algorithm* solves the sudoku grid. Some sudoku start configuration has more than one solution, in that case the program will output one of the solutions, and in case of no solution available for the sudoku start configuration, the program will output `This Grid Has No Solution!`.

## Sudoku Solving Algorithm

### Sudoku
Sudoku is a logic-based, combinatorial number-placement puzzle. In classic Sudoku, the objective is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 subgrids that compose the grid (also called "boxes", "blocks", or "regions") contain all of the digits from 1 to 9. The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution. [For more information on Sudoku](https://en.wikipedia.org/wiki/Sudoku) 

### Backtracing Algorithm
Backtracking is a class of problem-solving algorithms. An algorithm of that kind finds solution to computational problems that satisfies the problem's constraints. The algorithm uses the brute force approach, incrementally builds candidates to the solutions, and abandons a candidate as soon as it determines that the candidate is not a part of a valid solution (backtracks).

The *Sudoku Backtracking Algorithm* goes through the sudoku grid in a type-writer manner (left-to-right and downward) and methodically assign every cell a candidate in a way that doesn't violates the sudoku rules.
The algorithm point to the first empty cell and assign a candidate, number btween 1 and 9, when it finds a candidate that doesn't violate the sudoku rules it skips to the next vacant cell and does the same, until the algorithm reaches a cell where all the candidates violate the rules of sudoku. In this case the algorithm go back (Backtrack) to the 'previous changed cell' and inceament the value until a valid candidate is found, then the algorithm goes to the next vacant cell and assign candidates. If a valid candidate wasn't found, the algorithm skip to the 'previous changed cell' and so on.
### Pseudo-code
```
SudokuBacktrackingAlgorithm(grid[N][N])
{
   currentCell = (0,0);
   
   GoToNextVacantCell();
   
   while (grid is not solved)
    {
        if (AssignValidCandidate(currentCell) == true) {
              GoToNextVacantCell();
              if (currentCell == (9,*)
                  return 'Grid Is Solved';
        }
        else {
            GoToLastChangedCell()
            if (currentCell == (-1, *))
                  return 'Grid Has No Solution';
        }
    }
}

```
### Complexity

## Reference

http://pi.math.cornell.edu/~mec/Summer2009/meerkamp/Site/Introduction.html

https://en.wikipedia.org/wiki/Sudoku_solving_algorithms
