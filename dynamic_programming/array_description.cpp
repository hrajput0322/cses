// this approach will give tle in one test case... (but i am not able to understand its tabulation approach)
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int i, int m, int last, vector<int> &arr, vector<vector<int>> &dp) {
    if (i>=arr.size()) return 1;

    if (last!=-1 && dp[i][last]!=-1) return dp[i][last];

    int ans = 0;

    if (arr[i] == 0) { 
        if (i == 0) { 
            for (int j = 1; j <= m; j++) {
                ans = (ans + solve(i + 1, m, j, arr, dp)) % mod;
            }
        } else {
            for (int j = last - 1; j <= last + 1; j++) {
                if (j >= 1 && j <= m) {
                    ans = (ans + solve(i + 1, m, j, arr, dp)) % mod;
                }
            }
        }
    } else {
        if (i == 0 || abs(arr[i] - last) <= 1) {
            ans = (ans + solve(i + 1, m, arr[i], arr, dp)) % mod;
        } else {
            return 0;
        }
    }

    return dp[i][last] = ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    vector<vector<int>> dp(n, vector<int> (m+1, -1));
    cout<<solve(0, m, -1, arr, dp);
    return 0;
}