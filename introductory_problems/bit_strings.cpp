#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int x, int n) {
    if (n==0) return 1;

    long long val = solve(x, n/2);
    val = (val*val)%mod;

    if (n&1) return (val*x)%mod;
    return val;
}

int main(){
    int n;
    cin>>n;
    cout<<solve(2, n);
    return 0;
}