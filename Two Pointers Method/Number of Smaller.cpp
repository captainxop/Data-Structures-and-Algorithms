#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    int a[n], b[m];
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    int cnt = 0, i = 0, j = 0;
    while (j < m) {
        if (i != n && a[i] < b[j]) {
            cnt++;
            i++;
        }
        else {
            cout << cnt << " ";
            j++;
        }
    }
    
    cout << '\n';
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

// Problem Link:- https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
