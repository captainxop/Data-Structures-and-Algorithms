const int N = 2e5 + 5;
const int mod = 1000000007;
int fact[N];
int invfact[N];

int mult(int a, int b)
{
	int res = (a * 1LL * b) % mod;

	if (res < 0) {
		res += mod;
	}

	return res;
}

int power(int a, int b)
{
	int res = 1;

	while (b) {
		if (b % 2 == 1) {
			res = mult(a, res);
		}

		a = mult(a, a);
		b /= 2;
	}

	return res;
}

void precalc()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mult(i, fact[i - 1]) % mod;
	}

	invfact[N - 1] = power(fact[N - 1], mod - 2) % mod;
	for (int i = N - 2; i >= 0; i--) {
		invfact[i] = mult(invfact[i + 1], i + 1) % mod;
	}
}

int getnCr(int n, int r)
{
	if (r > n || n < 0 || r < 0) {
		return 0;
	}

	int res = mult(mult(fact[n], invfact[r]) % mod, invfact[n - r]) % mod;
	return res;
}