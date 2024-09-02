#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int i, int target, vector<int> &coins, vector<vector<int>> &dp) {
    if (i==0) {
        if (target%coins[0]==0) return 1;
        return 0;
    }

    if (dp[i][target]!=-1) return dp[i][target];

    int take = 0;
    if (target-coins[i]>=0) take = solve(i, target-coins[i], coins, dp);
    int not_take = solve(i-1, target, coins, dp);

    return dp[i][target] = (take+not_take)%mod;
}

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> coins(n);

    for (int i=0; i<n; i++) {
        cin>>coins[i];
    }

    vector<vector<int>> dp(n, vector<int> (target+1, 0));

    // cout<<solve(n-1, target, coins, dp);
    for (int j=0; j<=target; j++) {
        if (j%coins[0]==0) dp[0][j]=1;
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<=target; j++) {
            int take = 0;
            if (j-coins[i]>=0) take = dp[i][j-coins[i]];
            int not_take = dp[i-1][j];
            dp[i][j] = (take+not_take)%mod;
        }
    }

    cout<<dp[n-1][target];
    return 0;
}