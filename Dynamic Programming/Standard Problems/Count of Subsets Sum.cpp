#include <bits/stdc++.h>
using namespace std;

int CountSubsetDP(vector<int> a, int n, int sum)
{
    int dp[n + 1][sum + 1];
    
    for (int i = 0, j = 0; j <= sum; j++)
        dp[i][j] = 0;
    
    for (int i = 0, j = 0; i <= n; i++)
        dp[i][j] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (a[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
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
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << CountSubsetDP(a, n, sum) << '\n';
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
