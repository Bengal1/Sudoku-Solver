#include "common.h"
#include "candidate_check.h"


bool GetNextCell(int grid[N][N], int* row, int* col)
{
    while (true)
    {
        (*col)++;

        if (*col == N) {
            *col = 0;
            (*row)++;
            if (*row == N) {
                return false;
            }
        }
        if (grid[*row][*col] == EMPTY) {
            return true;
        }
    }
}

bool GetLastChangedCell(CellInformation gridData[N][N], int* row, int* col)
{
    while (true)
    {
        (*col)--;

        if (*col == -1) {
            *col = N - 1;
            (*row)--;
            if (*row == -1) {
                return false;
            }
        }
        if (gridData[*row][*col].numOfMarkUps != EMPTY) {
            return true;
        }
    }
}

bool AssignSimpleSolve(int grid[N][N], CellInformation* gridData, int row, int col, bool* direction)
{
    if (gridData->numOfMarkUps == EMPTY) {
        return *direction;
    }
    else {
        for (int num = grid[row][col]; num < N; num++) {
            if ((gridData->markUps[num] != EMPTY) && (!CheckViolation(grid, row, col, num + 1))) {
                grid[row][col] = num + 1;
                *direction = true;
                return true;
            }
        }
        grid[row][col] = EMPTY;
        *direction = false;
        return false;
    }
}

bool SimpleSolving(int grid[N][N], CellInformation gridData[N][N])
{
    int row = 0, col = 0;
    int* pRow = &row, * pCol = &col;
    bool directionFlag = true;

    while (true)
    {
        if (AssignSimpleSolve(grid, &gridData[row][col], row, col, &directionFlag)) {
            if (!GetNextCell(grid, pRow, pCol))
                return true;
        }
        else {
            if (!GetLastChangedCell(gridData, pRow, pCol))
                return false;
        }
    }
}
