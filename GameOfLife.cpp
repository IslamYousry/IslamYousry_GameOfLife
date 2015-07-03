//============================================================================
// Name        : sdfs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;

class gameOfLife {
private:
	bool ** grid;
	int size;
public:
	gameOfLife(int s = 38) {
		size = s;
		grid = new bool*[size];
		for (int i = 0; i < size; ++i) {
			grid[i] = new bool[size];
			for (int j = 0; j < size; ++j) {
				grid[i][j] = 0;
			}
		}
		initialize();
	}
	void initialize() {
		grid[5][1] = 1;
		grid[5][2] = 1;
		grid[6][1] = 1;
		grid[6][2] = 1;
		grid[3][13] = 1;
		grid[3][14] = 1;
		grid[4][12] = 1;
		grid[4][16] = 1;
		grid[5][11] = 1;
		grid[5][17] = 1;
		grid[6][11] = 1;
		grid[6][15] = 1;
		grid[6][17] = 1;
		grid[6][18] = 1;
		grid[7][11] = 1;
		grid[7][17] = 1;
		grid[8][12] = 1;
		grid[8][16] = 1;
		grid[9][13] = 1;
		grid[9][14] = 1;
		grid[1][25] = 1;
		grid[2][23] = 1;
		grid[2][25] = 1;
		grid[3][21] = 1;
		grid[3][22] = 1;
		grid[4][21] = 1;
		grid[4][22] = 1;
		grid[5][21] = 1;
		grid[5][22] = 1;
		grid[6][23] = 1;
		grid[6][25] = 1;
		grid[7][25] = 1;
		grid[3][35] = 1;
		grid[3][36] = 1;
		grid[4][35] = 1;
		grid[4][36] = 1;
	}

	int NCount(int i, int j) {
		int dir[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 },
				{ 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		int N = 0;
		for (int k = 0; k < 8; ++k) {
			if (i + dir[k][0] >= 0 && i + dir[k][0] < size && j + dir[k][1]
					>= 0 && j + dir[k][1] < size)
				if (grid[i + dir[k][0]][j + dir[k][1]] == 1)
					N++;
		}
		return N;
	}
	void run() {
		bool** newGrid = new bool*[size];
		for (int i = 0; i < size; ++i) {
			newGrid[i] = new bool[size];
			for (int j = 0; j < size; ++j) {
				int NC = NCount(i, j);
				if (grid[i][j] == 1) {
					if (NC == 2 || NC == 3) {
						newGrid[i][j] = 1;
					} else {
						newGrid[i][j] = 0;
					}
				} else {
					if (NC == 3)
						newGrid[i][j] = 1;
					else
						newGrid[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				grid[i][j] = newGrid[i][j];
			}

		}
		for (int i = 0; i < size; ++i) {
			delete [] newGrid[i];
		}
		delete [] newGrid;
	}

	void print() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if(grid[i][j] == 0)
                              cout << " " ;
                else 
                             cout << "*";
			}
			cout << endl;
		}
		cout << "----\n";
	}

};

int main() {
	gameOfLife gol;
	while (1) {
		gol.print();
		gol.run();
        if(kbhit())
            break;
		system("CLS");
	}
	system("pause");
	return 0;
}
