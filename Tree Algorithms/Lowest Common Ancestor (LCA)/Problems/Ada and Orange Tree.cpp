//Problem: https://www.spoj.com/problems/ADAORANG/

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

const int MAXN = 5e5 + 10;
const int LOG = 24;
vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN], shades[MAXN], sub[MAXN];

bitset<251> dfs(int u, int p = -1)
{
	bitset<251> b;
	for (auto v : adj[u]) {
		if (v == p) continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;
		for (int j = 1; j < LOG; j++) {
			if (up[v][j - 1] != -1) {
				up[v][j] = up[up[v][j - 1]][j - 1];
			}
		}

		bitset<251> t = dfs(v, u);
		b |= t;
	}

	b[shades[u]] = 1;
	sub[u] = b.count();

	return b;
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

void solve()
{
	rep(i, 0, MAXN) adj[i].clear();
	mem1(up);

	int n, q, r;
	cin >> n >> q >> r;

	rep(i, 0, n) cin >> shades[i];

	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(r);

	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << sub[get_lca(u, v)] << '\n';
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
	cin >> t;
	while (t--) solve();

	return 0;
}