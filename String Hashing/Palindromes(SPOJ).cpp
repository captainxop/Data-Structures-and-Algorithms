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

#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int N = 30000 + 5;
const int base = 33;
const int mod1 = 1e9 + 7;

int add(int a, int b, int mod)
{
    int res = (a + b) % mod;
    
    if (res < 0) {
        res += mod;
    }
    
    return res;
}

int mult(int a, int b, int mod)
{
    int res = (a * 1LL * b) % mod;
    
    if (res < 0) {
        res += mod;
    }
    
    return res;
}

int power(int a, int b, int mod)
{
    int res = 1;
    
    while (b) {
        if (b % 2 == 1) {
            res = mult(res, a, mod);
        }
        
        a = mult(a, a, mod);
        b /= 2;
    }
    
    return res;
}

int pw[N];
int inv[N];

void precalc()
{
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = mult(pw[i - 1], base, mod1);
    }
    
    int pw_inv = power(base, mod1 - 2, mod1);
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        inv[i] = mult(inv[i - 1], pw_inv, mod1);
    }
}

void build(string s, int(&hash)[N])
{
    int n = s.length();
    for (int i = 0; i < n; i++) {
        hash[i] = add((i == 0) ? 0 : hash[i - 1], mult(s[i] - 'a' + 1, pw[i], mod1), mod1);
    }
}

int gethash(int x, int y, int(&hash)[N])
{
    int res = add(hash[y], (x == 0) ? 0 : -hash[x - 1], mod1);
    res = mult(res, inv[x], mod1);
    return res;
}

void solve()
{
    int myhash[N];
    int invhash[N];
    
    int k;
    string s;
    cin >> k >> s;
    
    string st = string(s.rbegin(), s.rend());
    
    build(s, myhash);
    build(st, invhash);
    ll count = 0;
    int l = 0, r = k - 1, n = s.length();
    
    while (r < n) {
        int hash1 = gethash(l, r, myhash);
        int hash2 = gethash(n - 1 - r, n - 1 - l, invhash);
        
        if (hash1 == hash2) 
            count++;
        
        l++; r++;
    }
    
    cout << count << '\n';
}

int main()
{
    fastio;
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
    
    precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) solve();
    
    return 0;
}

// Problem Link:- https://www.spoj.com/problems/PLD/
