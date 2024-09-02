#include<bits/stdc++.h>
using namespace std;

// int solve(int i, int j, string s, string t, vector<vector<int>> &dp) {
//     if (i==0) return j;
//     if (j==0) return i;

//     if (dp[i][j]!=-1) return dp[i][j];

//     if (s[i-1]==t[j-1]) return dp[i][j] = solve(i-1, j-1, s, t, dp);
//     int add = 1 + solve(i, j-1, s, t, dp);
//     int del = 1 + solve(i-1, j, s, t, dp);
//     int replace = 1 + solve(i-1, j-1, s, t, dp);

//     return dp[i][j] = min({add, del, replace});
// }

int main() {
    string s, t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    // cout<<solve(n, m, s, t, dp);
    for (int i=0; i<n+1; i++) {
        dp[i][0] = i;
    }
    for (int j=0; j<m; j++) {
        dp[0][j] = j;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                int add = 1 + dp[i][j-1];
                int del = 1 + dp[i-1][j];
                int replace = 1 + dp[i-1][j-1];
                dp[i][j] = min({add, del, replace});
            }
        }
    }

    cout<<dp[n][m];
    return 0;
}