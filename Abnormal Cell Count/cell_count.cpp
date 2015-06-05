/* based off a solution form Koffman where we count how big an abnormal blob is in a grid given a location */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum cell {N, A, T}; // N is a normal cell, A is abnormal, and T is a temporary placeholder for counted cell

const int ROW_SIZE = 6;
const int COL_SIZE = 6;

int count_cells(cell grid[ROW_SIZE][COL_SIZE], int r, int c) {
	if (r < 0 || r > ROW_SIZE || c < 0 || c > COL_SIZE) {
		return 0;
	}
	else if (grid[r][c] != A) {
		return 0;
	}
	
	else {
		grid[r][c] = T;
		return 1
		// recursive call on cell to left and rigth of current cell
		+ count_cells(grid, r    , c - 1) + count_cells(grid, r    , c + 1)
		// recursive call on cell to top and bottom of current cell
		+ count_cells(grid, r - 1, c    ) + count_cells(grid, r + 1, c    )
		// recursive call on cell to topleft and topright corner of cell
		+ count_cells(grid, r - 1, c - 1) + count_cells(grid, r - 1, c + 1)
		// recursive call on cell to botleft and botright corner of cell
		+ count_cells(grid, r + 1, c - 1) + count_cells(grid, r + 1, c + 1);
	}
}

int main() {
	
	// this stuff is pretty useless for now except for printing out how the grid looks
	string line;
	ifstream map;
	map.open("map.txt");
	cout << "This is how the grid looks like, areas marked in A are abnormal blob cells: " << endl;
	while (getline(map, line)) {
		cout << line << endl;
	}
	
	// need to implement a way to get the map from a text file to this grid
	cell grid[ROW_SIZE][COL_SIZE] = 
	{{N, N, N, N, N, N},
	 {N, N, A, N, N, N},
	 {N, N, A, A, N, N},
	 {N, N, N, N, N, A},
	 {N, N, N, N, N, A},
	 {N, N, N, N, N, N}};
	int row;
	int col;
	cout << "Which row would you like to start at (first is 0)" << endl;
	cin >> row;
	cout << "Which column would you like to start at (first is 0)" << endl;
	cin >> col;
	cout << "This is how big the blob at " << row << ", " << col << " is: " << endl;
	cout << count_cells(grid, row, col) << endl;
	return 0;
}