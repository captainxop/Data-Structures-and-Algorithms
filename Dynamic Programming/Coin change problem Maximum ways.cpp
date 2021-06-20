#include <bits/stdc++.h>
using namespace std;

int CoinChange(vector<int> v, int n, int s)
{
    int dp[n + 1][s + 1];
    
    for (int i = 0; i <= s; i++)
        dp[0][i] = 0;
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (v[i - 1] <= j) {
                dp[i][j] = dp[i][j - v[i - 1]] + dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][s];
}

void solve()
{
    int n, s;
    cin >> n >> s;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << CoinChange(v, n, s) << '\n';
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
