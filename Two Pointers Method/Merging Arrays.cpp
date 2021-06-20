#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    int a[n], b[m], c[n + m];
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    int i = 0, j = 0, k = 0;
    
    while (i < n || j < m) {
        if (j == m || (i < n && a[i] < b[j])) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }
    
    for (int x : c) cout << x << " ";
    cout << '\n';
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    //cin>>t;
    while (t--) solve();
    
    return 0;
}

// Problem Link:- https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
