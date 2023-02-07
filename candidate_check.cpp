#include "common.h"

#define ADD 1
#define ERASE 3


bool CheckViolation(int grid[N][N], const int currentRow, const int currentCol, const int number)
{
    int boxCornerRow = currentRow - (currentRow % (N / 3));
    int boxCornerCol = currentCol - (currentCol % (N / 3));

    for (int col = 0; col < N; col++) { // by row
        if (grid[currentRow][col] == number)
            return true;
    }
    for (int row = 0; row < N; row++) { // by column
        if (grid[row][currentCol] == number)
            return true;
    }
    for (int row = 0; row < 3; row++) { // by box
        for (int col = 0; col < 3; col++) {
            if ((boxCornerRow + row) == currentRow && (boxCornerCol + col) == currentCol)
                continue;
            else if (grid[boxCornerRow + row][boxCornerCol + col] == number)
                return true;
        }
    }
    return false;
}


void UpdateMarkUps(CellInfo* cellData, const int number, const int action)
{
    switch (action) {
    case ADD: {
        if (cellData->markUps[number - 1] == EMPTY) {
            cellData->numOfMarkUps++;
            cellData->markUps[number - 1] = number;
        }
        else {
            if (cellData->markUps[number - 1] == number) {
                return;
            }
            else {
                exit(EXIT_FAILURE);
            }
        }
        return;
    }
    case ERASE: {
        cellData->numOfMarkUps = EMPTY;
        for (int i = 0; i < N; i++) {
            cellData->markUps[i] = EMPTY;
        }
        return;
    }
    default:
        return;
    }
}

int GetSingleValue(CellInfo* cellData, const int value)
{
    int returnValue = 0;

    if (value != EMPTY) {
        returnValue = value;
    }
    else if (value == EMPTY && (cellData->numOfMarkUps == 1)) {
        for (int i = 0; i < N; i++) {
            if (cellData->markUps[i] != EMPTY) {
                returnValue = cellData->markUps[i];
                break;
            }
        }
    }
    else
        exit(EXIT_FAILURE);

    UpdateMarkUps(cellData, EMPTY, ERASE);

    return returnValue;
}


void CandidateChecking(int grid[N][N], CellInfo gridData[N][N])  //make it more dynamic
{
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == EMPTY) {
                for (int num = 0; num < N; num++) {
                    if (!CheckViolation(grid, row, col, num + 1)) {
                        UpdateMarkUps(&gridData[row][col], num + 1, ADD);
                    }
                }
                if (gridData[row][col].numOfMarkUps == 1) {
                    grid[row][col] = GetSingleValue(&gridData[row][col], EMPTY);
                }
            }
        }
    }
    return;
}
