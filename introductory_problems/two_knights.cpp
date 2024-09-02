#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        long long total_ways = (1LL*i*i)*(i*i - 1)/2;
        long long attack_ways = 4*1LL*(i-1)*(i-2);
        cout<<total_ways-attack_ways<<"\n";
    }
    return 0;
}