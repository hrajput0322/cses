#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    int x = 5;
    while ((n/x)>0) {
        ans += floor(n/x);
        x = x*5;
    }
    cout<<ans;
    return 0;
}