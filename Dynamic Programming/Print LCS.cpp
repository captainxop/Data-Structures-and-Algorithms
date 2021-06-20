#include <bits/stdc++.h>
using namespace std;

string PrintLCS(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int dp[n + 1][m + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    int i = n, j = m;
    string lcs;
    
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs.push_back(s1[i - 1]);
            i--, j--;
        }
        else {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    
    reverse(lcs.begin(), lcs.end());
    
    return lcs;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << PrintLCS(s1, s2) << '\n';
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
