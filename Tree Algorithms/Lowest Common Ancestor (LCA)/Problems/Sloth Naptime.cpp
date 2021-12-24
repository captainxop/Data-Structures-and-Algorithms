//Problem: https://codeforces.com/gym/102694/problem/C

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

const int MAXN = (int)3e5 + 10;
const int LOG = 20;
vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int p = -1)
{
	for (auto v : adj[u]) {
		if (v == p) continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;
		rep(j, 1, LOG) {
			up[v][j] = up[up[v][j - 1]][j - 1];
		}

		dfs(v, u);
	}
}

int get_lca(int u, int v)
{
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int k = depth[u] - depth[v];
	repR(j, LOG - 1, 0) {
		if (k & (1 << j)) {
			u = up[u][j];
		}
	}

	if (u == v) return u;

	repR(j, LOG - 1, 0) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}

	return up[u][0];
}

int get_pos(int u, int v, int c)
{
	int lca = get_lca(u, v);
	int d = depth[u] + depth[v] - 2 * depth[lca];

	if (c >= d) return v;
	else if (c >= depth[u] - depth[lca]) {
		c -= (depth[u] - depth[lca]);
		c = depth[v] - depth[lca] - c;
		repR(j, LOG - 1, 0) {
			if (c & (1 << j)) {
				v = up[v][j];
			}
		}

		return v;
	}
	else {
		repR(j, LOG - 1, 0) {
			if (c & (1 << j)) {
				u = up[u][j];
			}
		}

		return u;
	}
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(0);

	int q;
	cin >> q;

	while (q--) {
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		cout << get_pos(u, v, c) + 1 << '\n';
	}
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