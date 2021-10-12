ll binpow(ll a, ll b, ll m)
{
	ll res = 1;
	a %= m;

	while (b) {
		if (b & 1) {
			res = (res * a) % m;
		}

		a = (a * a) % m;
		b /= 2;
	}

	return res;
}