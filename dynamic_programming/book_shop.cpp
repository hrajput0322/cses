#include<bits/stdc++.h>
using namespace std;

// int solve(int i, int x, vector<int> &price, vector<int> &page, vector<vector<int>> &dp) {
//     if (i==0) {
//         if (x-price[i]>=0) return page[i];
//         else return 0;
//     }

//     if (dp[i][x]!=-1) return dp[i][x];

//     int take = 0;
//     if (x-price[i]>=0) take = page[i]+solve(i-1, x-price[i], price, page, dp);
//     int not_take = solve(i-1, x, price, page, dp);

//     return dp[i][x] = max(take, not_take);
// }

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> price(n);
    vector<int> page(n);
    for (int i=0; i<n; i++) {
        cin>>price[i];
    }
    for (int i=0; i<n; i++) {
        cin>>page[i];
    }
    vector<vector<int>> dp(n, vector<int> (x+1, 0));
    // cout<<solve(n-1, x, price, page, dp);
    for (int j=0; j<=x; j++) {
        if (j-price[0]>=0) dp[0][j] = page[0];
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<=x; j++) {
            int take = 0;
            if (j-price[i]>=0) take = page[i]+dp[i-1][j-price[i]];
            int not_take = dp[i-1][j];

            dp[i][j] = max(take, not_take);
        }
    }

    cout<<dp[n-1][x];

    return 0;
}