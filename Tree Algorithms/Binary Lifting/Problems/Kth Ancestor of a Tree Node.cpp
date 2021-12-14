// Problem: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

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

vector<vector<int>> up, adj;
vector<int> depth;
int LOG;

void dfs(int u, int p = -1)
{
	for (auto v : adj[u]) {
		if (v == p) continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;
		for (int j = 1; j < LOG; j++) {
			up[v][j] = up[up[v][j - 1]][j - 1];
		}

		dfs(v, u);
	}
}

void TreeAncestor(int n, vector<int>& parent)
{
	LOG = 0;
	while ((1 << LOG) <= n) {
		LOG++;
	}

	up = vector<vector<int>> (n, vector<int> (LOG));
	depth = vector<int> (n);
	adj = vector<vector<int>> (n);

	for (int i = 1; i < n; i++) {
		adj[parent[i]].push_back(i);
		adj[i].push_back(parent[i]);
	}

	dfs(0, -1);
}

int getKthAncestor(int node, int k)
{
	if (depth[node] < k) return -1;

	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			node = up[node][j];
		}
	}

	return node;
}

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<int> parent(n);
	for (auto &x : parent) cin >> x;

	TreeAncestor(n, parent);

	while (q--) {
		int node, k;
		cin >> node >> k;
		cout << getKthAncestor(node, k) << '\n';
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