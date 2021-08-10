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

ll Merge(vector<int> l, vector<int> r, vector<int> &a)
{
	int n = sz(l), m = sz(r), i = 0, j = 0, k = 0;
	ll cnt = 0;

	while (i < n && j < m) {
		if (l[i] > r[j]) {
			cnt += (n - i);
			a[k++] = r[j++];
		}
		else {
			a[k++] = l[i++];
		}
	}

	while (i < n) a[k++] = l[i++];
	while (j < m) a[k++] = r[j++];

	return cnt;
}

void inversionCount(vector<int> &a, int n, ll &ans)
{
	if (n < 2) return;

	int mid = n / 2;

	vector<int> l(mid), r(n - mid);
	for (int i = 0; i < mid; i++) l[i] = a[i];
	for (int i = mid; i < n; i++) r[i - mid] = a[i];

	inversionCount(l, mid, ans);
	inversionCount(r, n - mid, ans);
	ans += Merge(l, r, a);
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];

	ll ans = 0;
	inversionCount(a, n, ans);

	cout << ans << '\n';
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

//Problem: https://www.geeksforgeeks.org/counting-inversions/
