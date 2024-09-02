#include<bits/stdc++.h>
using namespace std;

long long solve(int l, int r, vector<int> &arr, vector<vector<long long>> &dp) {
    if (l>r) {
        return 0;
    }

    if (dp[l][r]!=-1) return dp[l][r];

    long long p1 = LONG_LONG_MIN;
    p1 = max(p1, arr[l] + min(solve(l+2, r, arr, dp), solve(l+1, r-1, arr, dp)));
    p1 = max(p1, arr[r] + min(solve(l+1, r-1, arr, dp), solve(l, r-2, arr, dp)));

    return dp[l][r] = p1;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    vector<vector<long long>> dp(n, vector<long long> (n, -1));
    cout<<solve(0, n-1, arr, dp);
    return 0;
}