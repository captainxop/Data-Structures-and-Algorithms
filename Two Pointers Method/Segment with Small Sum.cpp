#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    ll s;
    cin >> n >> s;
    
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int i = 0, j = 0, l = 0, ans = 0;
    ll sum = 0;
    
    while (j < n) {
        if (sum + a[j] <= s) {
            sum += a[j];
            l++;
        }
        else {
            ans = max(ans, l);
            sum += a[j];
            l++;
            
            while (i <= j && sum > s) {
                sum -= a[i++];
                l--;
            }
        }
        
        j++;
    }
    
    ans = max(ans, l);
    
    cout << ans << '\n';
}

int main()
{
    /*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
    #endif*/
    
    int t = 1;
    //cin >> t;
    while (t--) solve();
    
    return 0;
}

// Problem Link:- https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A
