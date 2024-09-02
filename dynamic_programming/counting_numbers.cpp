#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

long long dp[19][2][2][11];

long long solve(int i, int tight1, int tight2, string num1, string num2, int n, int last_digit) {
    if (i==n) return 1LL;

    if (dp[i][tight1][tight2][last_digit]!=-1) return dp[i][tight1][tight2][last_digit];

    int low = (tight1==1)?num1[i]-'0':0;
    int high = (tight2==1)?num2[i]-'0':9;

    long long count = 0;

    for (int j=low; j<=high; j++) {
        if (j!=last_digit) count += solve(i+1, tight1&(j==low), tight2&(j==high), num1, num2, n, j);
    }

    return dp[i][tight1][tight2][last_digit] = count;
}

int main() {

        long long n1, n2;
        cin>>n1>>n2;

        string num1 = to_string(n1);
        string num2 = to_string(n2);

        int n = num1.length();
        int m = num2.length();

        num1 = string(m-n, '0') + num1;
        n = m;

        memset(dp, -1, sizeof(dp));
        long long a = solve(0, 1, 1, num1, num2, n, 10);
        cout<<a<<"\n";
    
    return 0;
}