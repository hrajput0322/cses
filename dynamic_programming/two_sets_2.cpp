#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int i, int n, int sum, vector<vector<int>> &dp) {
    if (sum<0) return 0;
    if (i==n) {
        if (sum-n==0) return 1;
        return 0;
    }

    if (dp[i][sum]!=-1) return dp[i][sum];

    int pick = solve(i+1, n, sum-i, dp);
    int not_pick = solve(i+1, n, sum, dp);

    return dp[i][sum] = (pick+not_pick)%mod;
}

int main(){
    int n;
    cin>>n;
    int sum = (n*(n+1))/2;
    if (sum&1) {
        cout<<0;
        return 0;
    }
    vector<vector<int>> dp(n+1, vector<int> (sum/2+1, -1));
    cout<<solve(1, n, sum/2, dp);
    return 0;
}