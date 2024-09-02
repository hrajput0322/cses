#include <bits/stdc++.h>
using namespace std;

long long solve(int i, long long sum, vector<long long> &arr, long long total_sum) {
    if (i == arr.size()) {
        return abs(2 * sum - total_sum);
    }

    long long pick = solve(i + 1, sum + arr[i], arr, total_sum);
    long long not_pick = solve(i + 1, sum, arr, total_sum);

    return min(pick, not_pick);
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }

    cout << solve(0, 0, arr, total_sum) << endl;
    return 0;
}
