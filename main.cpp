#include "common.h"
#include "candidate_check.h"
#include "simple_solving.h"

#define V_LINE "  |"
#define H_LINE "  -------------------------------"


void PrintSudokuGrid(int ar[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "  " << ar[i][j];
            if ((j < N - 1) && (j % (N / 3) == 2))
                cout << V_LINE;
        }
        cout << endl;
        if ((i < N - 1) && (i % (N / 3) == 2))
            cout << H_LINE << endl;
    }
    cout << endl;

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


    cout << " Start Sudoku Grid:" << endl;
    PrintSudokuGrid(sudokuGrid);

    CandidateChecking(sudokuGrid, gridInfo);

    if (!SimpleSolving(sudokuGrid, gridInfo)) {
        cout << "This Grid Has No Solution!" << endl;
        return 0;
    }

    cout << " Solution:" << endl;
    PrintSudokuGrid(sudokuGrid);

    return 0;
}
