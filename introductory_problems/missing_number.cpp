#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int xr1 = 0;
    for (int i=0; i<n-1; i++) {
        int x;
        cin>>x;
        xr1 = xr1^x;
    }
    for (int i=1; i<=n; i++) {
        xr1 = xr1^i;
    }

    cout<<xr1;
    return 0;
}