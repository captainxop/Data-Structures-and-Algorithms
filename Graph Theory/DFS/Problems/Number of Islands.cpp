//Problem Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int Maxn = 501;
int M[Maxn][Maxn];
bool visited[Maxn][Maxn];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int n, int m, int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || M[x][y] == 0) return;
	visited[x][y] = 1;


	for (int i = 0; i < 8; i++) {
		dfs(n, m, x + dx[i], y + dy[i]);
	}
}

int countIslands(int n, int m)
{
	int islands = 0;
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && M[i][j]) {
				dfs(n, m, i, j);
				islands++;
			}
		}
	}

	return islands;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
		}
	}

	int ans = countIslands(n, m);
	cout << ans << '\n';
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