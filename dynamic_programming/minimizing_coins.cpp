#include<bits/stdc++.h>
using namespace std;

// int solve(int i, int sum, vector<int> &coins, vector<vector<int>> &dp) {
//     if (i==0) {
//         if (sum%coins[i]==0) return sum/coins[i];
//         return 1e9;
//     }

//     if (dp[i][sum]!=-1) return dp[i][sum];

//     int take = 1e9;
//     if (sum-coins[i]>=0) take = 1 + solve(i, sum-coins[i], coins, dp);
//     int not_take = solve(i-1, sum, coins, dp);

//     return dp[i][sum] = min(take, not_take);
// }

int main(){
    int n, sum;
    cin>>n>>sum;
    vector<int> coins(n);
    vector<vector<int>> dp(n, vector<int> (sum+1, 0));
    for (int i=0; i<n; i++) {
        cin>>coins[i];
    }

    // int ans = solve(n-1, sum, coins, dp);
    // if (ans>=1e9) cout<<-1;
    // else cout<<ans;

    for (int k=0; k<=sum; k++) {
        if (k%coins[0]==0) dp[0][k] = k/coins[0];
        else dp[0][k] = 1e9;
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<=sum; j++) {
            int take = 1e9;
            if (j-coins[i]>=0) take = 1 + dp[i][j-coins[i]];
            int not_take = dp[i-1][j];
            dp[i][j] = min(take, not_take);
        }
    }

    if (dp[n-1][sum]>=1e9) cout<<-1;
    else cout<<dp[n-1][sum];
    return 0;
}