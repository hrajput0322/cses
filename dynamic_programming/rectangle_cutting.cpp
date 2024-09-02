#include<bits/stdc++.h>
using namespace std;

// int solve(int x, int y, vector<vector<int>> &dp) {
//     if (x==y) return 0;

//     if (dp[x][y]!=-1) return dp[x][y];

//     int ans = INT_MAX;
    
//     for (int i=1; i<x; i++) {
//         ans = min(ans, 1 + solve(i, y, dp) + solve(x-i, y, dp));
//     }

//     for (int j=1; j<y; j++) {
//         ans = min(ans, 1 + solve(x, j, dp) + solve(x, y-j, dp));
//     }

//     return dp[x][y] = ans;
// }

int main(){
    int x, y;
    cin>>x>>y;
    vector<vector<int>> dp(x+1, vector<int> (y+1, INT_MAX));
    // cout<<solve(x, y, dp);
    for (int i=0; i<=x; i++) {
        for (int j=0; j<=y; j++) {
            if (i==j) dp[i][j] = 0;
        }
    }

    for (int p=1; p<=x; p++) {
        for (int q=1; q<=y; q++) {
            for (int i=1; i<p; i++) {
                dp[p][q] = min(dp[p][q], 1 + dp[i][q] + dp[p-i][q]);
            }
            for (int j=1; j<q; j++) {
                dp[p][q] = min(dp[p][q], 1 + dp[p][j] + dp[p][q-j]);
            }
        }
    }

    cout<<dp[x][y];
    return 0;
}