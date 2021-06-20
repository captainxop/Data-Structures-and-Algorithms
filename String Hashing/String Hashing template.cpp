const int N = 1e6 + 5;
const int mod1 = 1e9 + 7;
const int base = 33;

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
            res = mult(a, res, mod);
        }
        
        a = mult(a, a, mod);
        b /= 2;
    }
    
    return res;
}

int myhash[N];
int pw[N];
int inv[N];

void precalc()
{
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = mult(pw[i - 1], base, mod);
    }
    
    int pw_inv = power(base, mod - 2, mod);
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        inv[i] = mult(inv[i - 1], pw_inv, mod);
    }
}

void build(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++) {
        myhash[i] = add((i == 0) ? 0 : myhash[i - 1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
    }
}

int gethash(int x, int y)
{
    int res = add(myhash[y], (x == 0) ? 0 : -myhash[x - 1], mod);
    res = mult(res, inv[x], mod);
    return res;
}

// Resources and Further Readings:- 
// https://cp-algorithms.com/string/string-hashing.html#toc-tgt-7 
// https://codeforces.com/blog/entry/60445
