#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> l, vector<int> r, vector<int> &a)
{
	int n = l.size(), m = r.size(), i = 0, j = 0, k = 0;

	while (i < n && j < m) {
		if (l[i] <= r[j]) {
			a[k++] = l[i++];
		}
		else {
			a[k++] = r[j++];
		}
	}

	while (i < n) {
		a[k++] = l[i++];
	}

	while (j < m) {
		a[k++] = r[j++];
	}
}

void MergeSort(vector<int> &a, int n)
{
	if (n < 2)
		return;

	int mid = n / 2;
	vector<int> l(mid), r(n - mid);

	for (int i = 0; i < mid; i++)
		l[i] = a[i];

	for (int i = mid; i < n; i++)
		r[i - mid] = a[i];

	MergeSort(l, mid);
	MergeSort(r, n - mid);
	merge(l, r, a);
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	MergeSort(a, n);

	for (auto x : a) {
		cout << x << " ";
	}
}

int main()
{
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
