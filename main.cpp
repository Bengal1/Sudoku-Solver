#include "common.h"
#include "candidate_check.h"
#include "simple_solving.h"

#define V_LINE "  |"
#define H_LINE "  -------------------------------"


void PrintSudokuGrid(int ar[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "  " << ar[i][j];
            if ((j < N - 1) && (j % (N / 3) == 2))
                std::cout << V_LINE;
        }
        std::cout << std::endl;
        if ((i < N - 1) && (i % (N / 3) == 2))
            std::cout << H_LINE << std::endl;
    }
    std::cout << std::endl;

    return;
}

int main()
{
    CellInformation gridInfo[N][N];
    int sudokuGrid[N][N] = {    {1, 0, 3,  0, 0, 4,  0, 8, 7},
                                {0, 0, 0,  9, 0, 0,  0, 6, 0},
                                {0, 8, 0,  0, 0, 0,  0, 0, 0},

                                {0, 0, 2,  0, 0, 0,  0, 0, 0},
                                {5, 0, 7,  0, 0, 3,  0, 0, 1},
                                {0, 0, 0,  0, 4, 0,  3, 0, 0},

                                {0, 4, 0,  0, 0, 0,  0, 0, 8},
                                {8, 0, 5,  0, 6, 0,  0, 7, 0},
                                {0, 2, 0,  0, 0, 5,  0, 0, 0} };


    std::cout << " Start Sudoku Grid:" << std::endl;
    PrintSudokuGrid(sudokuGrid);

    CandidateChecking(sudokuGrid, gridInfo);

    if (!SimpleSolving(sudokuGrid, gridInfo)) {
        std::cout << "This Grid Has No Solution!" << std::endl;
        return 0;
    }

    std::cout << " Solution:" << std::endl;
    PrintSudokuGrid(sudokuGrid);

    return 0;
}
