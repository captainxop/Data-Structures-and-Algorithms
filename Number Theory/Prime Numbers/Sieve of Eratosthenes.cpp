const int N = 2e5;
bool isPrime[N + 10];
vector<int> primes;

void sieve()
{
    for(int i = 0; i <= N; i++) {
        isPrime[i] = true;
    }
    
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i] && i * i <= N) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    primes.pb(2);
    for (int i = 3; i <= N; i += 2) {
        if (isPrime[i]) 
            primes.pb(i);
    }
}
