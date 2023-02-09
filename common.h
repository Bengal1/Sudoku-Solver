#ifndef COMMON_H
#define COMMON_H

#include <iostream>
using namespace std;


#define EMPTY 0
#define N 9


struct CellInformation {
	int markUps[N];
	int numOfMarkUps;
	
	CellInformation() {
		numOfMarkUps = 0;
		for (int i = 0; i < N; i++)
			markUps[i] = 0;
	}
};


#endif //COMMON_H