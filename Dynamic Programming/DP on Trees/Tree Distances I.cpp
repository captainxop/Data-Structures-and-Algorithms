//Problem: https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ppb pop_back
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
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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

/*---------------------------------------------------------Debugging----------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------------------------------------------*/

const int MAXN = (int) 2e5 + 10;
vector<int> adj[MAXN];
int in[MAXN], out[MAXN], ans[MAXN];
pair<int, int> max_two[MAXN];

/*
in-out dp

in[u] = max distance for a node u in its subtree
out[u] = max distance for a node u outside its subtree
ans[u] = max distance of a node from this node

in[u] = 1 + max in [ci], ith child of u
out[u] = max(1 + out[parent], 1 + 1 + max of in[i]), ith sibling of u
ans[u] = max(in[u], out[u])
*/

void dfs1(int u, int p = 0)
{
	int f = 0, s = 0;

	for (auto v : adj[u]) {
		if (v != p) {
			dfs1(v, u);
			in[u] = max(in[u], 1 + in[v]);

			if (in[v] >= in[f]) {
				s = f;
				f = v;
			}
			else if (in[v] > in[s]) {
				s = v;
			}
		}
	}

	max_two[u] = {f, s};
}

void dfs2(int u, int p = 0)
{
	for (auto v : adj[u]) {
		if (v != p) {
			out[v] = 1 + out[u];
			int f = max_two[u].ff;
			int s = max_two[u].ss;

			if (f != v && f != 0) {
				out[v] = max(out[v], 2 + in[f]);
			}
			else if (s != 0) {
				out[v] = max(out[v], 2 + in[s]);
			}

			dfs2(v, u);
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs1(1); // calculate in array
	dfs2(1); // calculate out array

	rep(i, 1, n + 1) {
		ans[i] = max(in[i], out[i]);
	}

	rep(i, 1, n + 1) {
		cout << ans[i] << ' ';
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("Error.txt", "w", stderr);
#endif

	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}