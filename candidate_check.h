#ifndef CANDIDATE_CHECK_H
#define CANDIDATE_CHECK_H

#include "common.h"

bool CheckViolation(int grid[N][N], const int currentRow, const int currentCol, const int number);

void CandidateChecking(int grid[N][N], CellInfo gridData[N][N]);

#endif //CANDIDATE_CHECK