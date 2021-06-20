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

//#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int N = 3e6 + 5;
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

int myhash[N];
int needle[N];
int pw[N];
int inv[N];

void precalc(int mod)
{
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = mult(pw[i - 1], base, mod);
    }
    
    int inv_power = power(base, mod - 2, mod);
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        inv[i] = mult(inv[i - 1], inv_power, mod);
    }
}

void build(string s, int (&hash)[N], int mod)
{
    int n = s.length();
    for (int i = 0; i < n; i++) {
        hash[i] = add((i == 0) ? 0 : hash[i - 1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
    }
}

int gethash(int x, int y, int (&hash)[N], int mod)
{
    int res = add(hash[y], (x == 0) ? 0 : -hash[x - 1], mod);
    res = mult(res, inv[x], mod);
    return res;
}

void solve()
{
    int n;
    
    while (cin >> n)
    {
        string s1, s2;
        cin >> s1 >> s2;
        
        build(s2, myhash, mod1);
        build(s1, needle, mod1);
        
        int hash1 = gethash(0, n - 1, needle, mod1);
        int needle_size = n, haysize = (int)s2.length();
        int flag = 0;
        
        for (int l = 0; l < haysize; l++) {
            int r = l + needle_size - 1;
            int hash2 = gethash(l, r, myhash, mod1);
            
            if (hash1 == hash2) {
                flag = 1;
                cout << l << '\n';
            }
        }
        
        if (flag == 0) {
            cout << '\n';
        }
        
        cout << '\n';
    }
}

int main()
{
    fastio;
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
    
    precalc(mod1);
    
    int t = 1;
    //cin >> t;
    while (t--) solve();
    
    return 0;
}

// Problem Link:- https://www.spoj.com/problems/NHAY/
