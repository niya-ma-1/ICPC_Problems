#include <iostream>
#include <vector>
#include <string>

using namespace std;

int DFS(vector <string> & grid, int x, int y);

int main(void)
{
	int numTestcases = 0;
	cin >> numTestcases;
	while (numTestcases--) {
		int x, y;

		cin >> x >> y;
		--x;
		--y;
		getchar();
		vector <string> grid;//water=0, land=1

		while (true){
			string input;
			getline(std::cin, input);

			if(input == "")
				break;

			grid.push_back(input);
		}

		cout << DFS(grid, x, y) << endl;

		if (numTestcases)
			cout << endl;
	}

	return 0;
}

int DFS(vector <string> & grid, int x, int y)
{
	int m = grid.size();
	int n = grid[0].size();

	int count = 1;
	grid[x][y] = '1';

	int xs[] = {-1, 0, 0, 1};
	int ys[] = {0, -1, 1, 0};


	for (int i = 0; i < 4; ++i){
		int nx = x + xs[i];
		int ny = y + ys[i];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '0')
			count += DFS(grid, nx, ny);
	}

	return count;
}