#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll MinCoins(vector<int> v, int n, int sum)
{
    ll dp[n + 1][sum + 1];
    
    for (int i = 0; i <= sum; i++) {
        dp[0][i] = INT_MAX;
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (v[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - v[i - 1]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][sum];
}

void solve()
{
    int n, sum;
    cin >> n >> sum;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    ll ans = MinCoins(v, n, sum);
    
    if (ans == INT_MAX)
        ans = -1;
    
    cout << ans << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
