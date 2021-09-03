ll mult(ll a, ll b)
{
	ll res = (a * b) % mod;

	if (res < 0) {
		res += mod;
	}

	return res;
}

ll power(ll a, ll b)
{
	ll res = 1;

	while (b) {
		if (b % 2 == 1) {
			res = mult(a, res);
		}

		a = mult(a, a);
		b /= 2;
	}

	return res;
}