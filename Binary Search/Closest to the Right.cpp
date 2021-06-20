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

int Search(vi v, int n, int k)
{
    int low = -1, high = n, mid = 0;
    
    while (low + 1 < high) {
        mid = low + (high - low) / 2;
        
        if (v[mid] >= k) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    
    return high + 1;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    
    vi v(n);
    rep(i, 0, n) 
        cin >> v[i];
    
    rep(i, 0, q) {
        int k; cin >> k;
        int index = Search(v, n, k);
        cout << index << '\n';
    }
}

int main()
{
    fastio;
    
    /*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/
    
    int t = 1;
    //cin >> t;
    while (t--) solve();
    
    return 0;
}

// Problem Link:- https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
