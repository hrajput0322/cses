#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// int solve(int sum, vector<int> &coins, int n, vector<int> &dp) {
//     if (sum == 0) return 1;
    
//     if (dp[sum] != -1) return dp[sum];

//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         if (sum - coins[i] >= 0) {
//             ans = (ans + solve(sum - coins[i], coins, n, dp)) % mod;
//         }
//     }

//     return dp[sum] = ans;
// }

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(sum + 1, 0);

    for (int j=0; j<=sum; j++) {
        if (j==0) dp[j] = 1;
        else {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (j - coins[i] >= 0) {
                    ans = (ans + dp[j - coins[i]]) % mod;
                }
            }
            dp[j] = ans;
        }
    }

    cout << dp[sum];
    return 0;
}
