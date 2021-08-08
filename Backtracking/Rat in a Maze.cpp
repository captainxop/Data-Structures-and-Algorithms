#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int n;
int maze[101][101], path[101][101];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void Print()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}

		cout << '\n';
	}

	cout << '\n';
}

void ratMaze(int row, int col)
{
	if (row == n - 1 && col == n - 1) {
		path[row][col] = 1;
		Print();
		return;
	}

	if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || path[row][col] == 1) {
		return;
	}

	path[row][col] = 1;

	for (int i = 0; i < 4; i++) {
		ratMaze(row + dx[i], col + dy[i]);
	}

	path[row][col] = 0;
}

void solve()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	ratMaze(0, 0);
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}

//Problem: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/