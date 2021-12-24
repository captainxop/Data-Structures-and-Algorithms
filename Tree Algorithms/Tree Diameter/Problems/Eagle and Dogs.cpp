//Problem: https://www.spoj.com/problems/EAGLE1/

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
vector<pii> adj[MAXN];
ll dogs[MAXN];
ll node, max_d;

void dfs(int u, int p = -1, ll d = 0)
{
	dogs[u] = max(dogs[u], d);

	if (max_d < d) {
		max_d = d;
		node = u;
	}

	for (auto v : adj[u]) {
		if (v.ff != p) {
			dfs(v.ff, u, d + v.ss);
		}
	}
}

void solve()
{
	rep(i, 0, MAXN) {
		adj[i].clear();
		dogs[i] = 0;
	}

	int n;
	cin >> n;

	rep(i, 0, n - 1) {
		int u, v, d;
		cin >> u >> v >> d;
		--u, --v;
		adj[u].pb({v, d});
		adj[v].pb({u, d});
	}

	max_d = 0;
	dfs(0);
	max_d = 0;
	dfs(node);
	max_d = 0;
	dfs(node);

	rep(i, 0, n) cout << dogs[i] << ' ';
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