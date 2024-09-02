#include <bits/stdc++.h>
using namespace std;

// Memoization table to store results of subproblems
vector<long long> dp;

long long solve(int i, vector<pair<int, pair<int, int>>> &arr) {
    if (i >= arr.size()) return 0;

    // If result is already computed, return it
    if (dp[i] != -1) return dp[i];

    long long pick = 0;
    long long not_pick = 0;

    // Option 1: Do not pick the current interval
    not_pick = solve(i + 1, arr);

    // Option 2: Pick the current interval
    // Find the next interval that starts after the current one ends
    int ind = upper_bound(arr.begin(), arr.end(), make_pair(arr[i].second.first, make_pair(INT_MAX, INT_MAX))) - arr.begin();
    pick = arr[i].second.second + solve(ind, arr);

    // Store the result in the dp table and return the maximum of both options
    return dp[i] = max(pick, not_pick);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> arr(n);
    
    for (int i = 0; i < n; i++) {
        int start, end, reward;
        cin >> start >> end >> reward;
        arr[i] = {start, {end, reward}};
    }
    
    // Sort intervals based on start time
    sort(arr.begin(), arr.end());

    // Initialize the memoization table with -1 (indicating uncomputed subproblems)
    dp.assign(n, -1);

    // Start the recursion from the first interval
    cout << solve(0, arr) << endl;

    return 0;
}
