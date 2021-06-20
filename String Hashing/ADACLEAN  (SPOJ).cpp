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

const int N = 2e5 + 1;
const int base1 = 31;
const int base2 = 33;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

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

int pw1[N];
int pw2[N];
int inv1[N];
int inv2[N];

void precalc()
{
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = mult(pw1[i - 1], base1, mod1);
        pw2[i] = mult(pw2[i - 1], base2, mod2);
    }
    
    int inv_pw1 = power(base1, mod1 - 2, mod1);
    int inv_pw2 = power(base2, mod2 - 2, mod2);
    inv1[0] = 1;
    inv2[0] = 1;
    
    for (int i = 1; i < N; i++) {
        inv1[i] = mult(inv1[i - 1], inv_pw1, mod1);
        inv2[i] = mult(inv2[i - 1], inv_pw2, mod2);
    }
}

void build1(string s, int (&hash)[N])
{
    
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        hash[i] = add((i == 0) ? 0 : hash[i - 1], mult(pw1[i], s[i] - 'a' + 1, mod1), mod1);
    }
}

void build2(string s, int (&hash)[N])
{
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        hash[i] = add((i == 0) ? 0 : hash[i - 1], mult(pw2[i], s[i] - 'a' + 1, mod2), mod2);
    }
}

pii gethash1(int x, int y, int (&hash1)[N], int (&hash2)[N])
{
    pii p;
    
    int res1 = add(hash1[y], (x == 0) ? 0 : -hash1[x - 1], mod1);
    res1 = mult(res1, inv1[x], mod1);
    p.ff = res1;
    
    int res2 = add(hash2[y], (x == 0) ? 0 : -hash2[x - 1], mod2);
    res2 = mult(res2, inv2[x], mod2);
    p.ss = res2;
    
    return p;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    int myhash[N];
    int myhash2[N];
    
    build1(s, myhash);
    build2(s, myhash2);
    
    set<pii> st;
    int l = 0, r = k - 1;
    
    while (r < n) {
        pii p = gethash1(l, r, myhash, myhash2);
        st.insert(p);
        l++; r++;
    }
    
    cout << st.size() << '\n';
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
    cin >> t;
    while (t--) solve();
    
    return 0;
}

// Problem Link:- https://www.spoj.com/problems/ADACLEAN/
