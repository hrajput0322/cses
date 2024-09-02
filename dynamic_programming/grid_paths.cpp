#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int i, int j, vector<vector<char>> &grid, int n, vector<vector<int>> &dp) {
    if (i==0 && j==0) return 1;
    if (i<0 || i>=n || j<0 || j>=n || grid[i][j]=='*') return 0;

    if (dp[i][j]!=-1) return dp[i][j];
    
    int up = solve(i-1, j, grid, n, dp);
    int left = solve(i, j-1, grid, n, dp);

    return dp[i][j] = (up+left)%mod;
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char> (n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }
    if (grid[0][0]=='*' || grid[n-1][n-1]=='*') {
        cout<<0;
        return 0;
    };
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<solve(n-1, n-1, grid, n, dp);
    return 0;
}