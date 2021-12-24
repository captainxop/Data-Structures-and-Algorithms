//Problem: https://www.spoj.com/problems/DISQUERY/

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

const int MAXN = (int)1e5 + 10;
const int LOG = 24;
vector<pii> adj[MAXN];
int up[MAXN][LOG], min_up[MAXN][LOG], max_up[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int p = -1)
{
	for (auto v : adj[u]) {
		if (v.ff == p) continue;

		depth[v.ff] = depth[u] + 1;
		up[v.ff][0] = u;
		min_up[v.ff][0] = max_up[v.ff][0] = v.ss;

		for (int j = 1; j < LOG; j++) {
			up[v.ff][j] = up[up[v.ff][j - 1]][j - 1];
			min_up[v.ff][j] = min(min_up[v.ff][j - 1], min_up[up[v.ff][j - 1]][j - 1]);
			max_up[v.ff][j] = max(max_up[v.ff][j - 1], max_up[up[v.ff][j - 1]][j - 1]);
		}

		dfs(v.ff, u);
	}
}

int get_lca(int u, int v)
{
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int k = depth[u] - depth[v];
	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			u = up[u][j];
		}
	}

	if (u == v) return u;

	for (int j = LOG - 1; j >= 0; j--) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}

	return up[u][0];
}

pii helper(int u, int v)
{
	int mn = INT_MAX, mx = -1;
	int lca = get_lca(u, v);

	int k = depth[u] - depth[lca];
	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			mn = min(mn, min_up[u][j]);
			mx = max(mx, max_up[u][j]);
			u = up[u][j];
		}
	}

	k = depth[v] - depth[lca];
	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			mn = min(mn, min_up[v][j]);
			mx = max(mx, max_up[v][j]);
			v = up[v][j];
		}
	}

	return {mn, mx};
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 0, n - 1) {
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		adj[u].pb({v, c});
		adj[v].pb({u, c});
	}

	dfs(0);

	int q;
	cin >> q;

	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;

		pii p = helper(u, v);
		cout << p.ff << ' ' << p.ss << '\n';
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