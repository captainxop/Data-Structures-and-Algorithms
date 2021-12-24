#include <bits/stdc++.h>
using namespace std;

int Knapsack(vector<int> v, vector<int> weight, int n, int W)
{
    int dp[n + 1][W + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (weight[i - 1] <= j) {
                dp[i][j] = max(v[i - 1] + dp[i][j - weight[i - 1]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][W];
}

void solve()
{
    int n, W;
    cin >> n >> W;
    
    vector<int> v(n), weight(n);
    
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    
    cout << Knapsack(v, weight, n, W) << '\n';
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
