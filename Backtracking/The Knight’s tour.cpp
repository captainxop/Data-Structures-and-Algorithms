#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int board[10][10];
int n;
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2,  2, 1, -1, -2, -2, -1 };

void Print()
{
	rep(i, 0, n) {
		rep(j, 0, n) {
			cout << board[i][j] << " ";
		}

		cout << '\n';
	}
}

bool knightTour(int x, int y, int cnt)
{
	if (cnt == n * n) {
		return true;
	}

	rep(i, 0, 8) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == -1) {
			board[nx][ny] = cnt;

			if (knightTour(nx, ny, cnt + 1)) {
				return true;
			}
			else {
				board[nx][ny] = -1;
			}
		}
	}

	return false;
}

void solve()
{
	cin >> n;
	mem1(board);

	board[0][0] = 0;

	if (knightTour(0, 0, 1)) {
		Print();
	}
	else cout << "No Solution" << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}

//Problem: https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/