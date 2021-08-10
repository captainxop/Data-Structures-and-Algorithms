#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

bool check(vector<long long> pos, int n, int cows, long long d)
{
	cows--;
	int prev_pos = 0;

	for (int i = 1; i < n && cows > 0; i++) {
		if (pos[i] - pos[prev_pos] >= d) {
			cows--;
			prev_pos = i;
		}
	}

	if (cows == 0) return true;
	return false;
}

long long Search(vector<long long> pos, int n, int cows)
{
	long long l = 0, r = pos[n - 1] - pos[0], mid = 0, ans = -1;

	while (l <= r) {
		mid = l + (r - l) / 2;

		if (check(pos, n, cows, mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return ans;
}

void solve()
{
	int n, cows;
	cin >> n >> cows;

	vector<long long> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}

	sort(pos.begin(), pos.end());

	long long ans = Search(pos, n, cows);
	cout << ans << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}

// Problem: https://www.spoj.com/problems/AGGRCOW/