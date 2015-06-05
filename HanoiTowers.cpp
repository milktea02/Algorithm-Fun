/* Based on the solution from Koffman */

#include <iostream>
#include <string>

using namespace std;

void solveHanoi(int n, string start, string end, string temp) {
	if (n == 1) {
		cout << "move " << n << " from " << start << " to " << end << endl;
	}
	else{
		solveHanoi(n-1, start, temp, end);
		cout << "move " << n << " from " << start << " to " << end << endl;
		solveHanoi(n-1, temp, end, start);
	}
}

int main() {
	int levels;
	cout << "How many levels is your tower? " << endl;
	cin >> levels;
	solveHanoi(levels, "L", "R", "M");
	return 0;
	
}