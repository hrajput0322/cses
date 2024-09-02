#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp) {
    if (n<=9) return 1;

    if (dp[n]!=-1) return dp[n];

    vector<int> digits;
    int m = n;
    while (m) {
        digits.push_back(m%10);
        m = m/10;
    }

    int ans = INT_MAX;
    for (auto it: digits) {
        if (n-it>=0 && it!=0) ans = min(ans, 1 + solve(n-it, dp));
    }

    return dp[n] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<solve(n, dp);
    return 0;
}