// faaltu me zada variables mat leke rakho...
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solve(int target, vector<int> &dp) {
    if (target==0) return 1;

    if (dp[target]!=-1) return dp[target];

    int ans = 0;
    for (int i=1; i<=6; i++) {
        if (target-i>=0) ans = (ans + solve(target-i, dp))%mod;
    }

    return dp[target] = ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<solve(n, dp);
    return 0;
}