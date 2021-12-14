//Problem: https://www.codechef.com/problems/SPTREE

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

const int MAXN = (int)2e5 + 10;
const int LOG = 24;
vector<int> adj[MAXN];
vector<int> dist, nodes;
int up[MAXN][LOG];
int depth[MAXN], special[MAXN], sub[MAXN];

int dfs(int u, int p = -1)
{
	if (special[u]) sub[u] = u;
	for (auto v : adj[u]) {
		if (v == p) continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;
		for (int j = 1; j < LOG; j++) {
			if (up[v][j - 1] != -1) {
				up[v][j] = up[up[v][j - 1]][j - 1];
			}
		}

		int is_special = dfs(v, u);
		if (is_special != -1) sub[u] = is_special;
	}

	return sub[u];
}

void solve()
{
	mem1(up);
	rep(i, 0, MAXN) {
		adj[i].clear();
		depth[i] = 0;
		special[i] = 0;
		sub[i] = -1;
	}

	int n, k, a;
	cin >> n >> k >> a;
	--a;

	rep(i, 0, k) {
		int x;
		cin >> x;
		special[--x] = 1;
	}

	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(a);

	vector<int> ans(n), nodes(n);
	rep(i, 0, n) {
		int v = i;
		for (int j = LOG - 1; j >= 0; j--) {
			if (up[v][j] != -1 && sub[up[v][j]] == -1) {
				v = up[v][j];
			}
		}
		v = up[v][0];
		if (sub[i] != -1) v = i;

		ans[i] = (depth[v] - (depth[i] - depth[v]));
		nodes[i] = sub[v];
	}

	for (auto x : ans) cout << x << ' ';
	cout << '\n';
	for (auto x : nodes) cout << x + 1 << ' ';
	cout << '\n';
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
