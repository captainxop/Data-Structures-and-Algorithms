// Problem Link: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int dp[5][10001];

int cutSegments(int len[], int i, int n)
{
	if (n == 0) return 0;
	if (i == 0) return -1e9;
	if (dp[i][n] != -1) return dp[i][n];

	int x = 0, y = 0, z = 0;
	if (n - len[i - 1] >= 0) {
		x = 1 + cutSegments(len, i, n - len[i - 1]);
		y = 1 + cutSegments(len, i - 1, n - len[i - 1]);
		z = cutSegments(len, i - 1, n);
		dp[i][n] = max({x, y, z});
	}
	else {
		dp[i][n] = cutSegments(len, i - 1, n);
	}

	return dp[i][n];
}

void solve()
{
	int n;
	cin >> n;

	int len[3];
	for (int i = 0; i < 3; i++) {
		cin >> len[i];
	}

	memset(dp, -1, sizeof(dp));
	int ans = cutSegments(len, 3, n);
	cout << (ans < 0 ? 0 : ans) << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}