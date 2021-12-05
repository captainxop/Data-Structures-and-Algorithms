const int MAXN = 2e6 + 10;
bool isPrime[MAXN];

void sieve(ll n)
{
    isPrime[0] = isPrime[1] = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (!isPrime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}