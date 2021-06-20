#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;
    
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    ll ans = 0;
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        ll cnt1 = 1, cnt2 = 1;
        
        if (a[i] == b[j]) {
            while (i < n - 1 && a[i] == a[i + 1]) i++, cnt1++;
            while (j < m - 1 && b[j] == b[j + 1]) j++, cnt2++;
            
            ans += (cnt1 * 1LL * cnt2);
            i++, j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    
    cout << ans << '\n';
}

int main()
{
    
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    //cin >> t;
    while (t--) solve();
    
    return 0;
}

// Problem Link:- https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
