#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int maxi = arr[0];
    long long ans = 0;
    for (int i=1; i<n; i++) {
        if (arr[i]<maxi) {
            ans += maxi-arr[i];
        }
        else {
            maxi = arr[i];
        }
    }

    cout<<ans;
    return 0;
}