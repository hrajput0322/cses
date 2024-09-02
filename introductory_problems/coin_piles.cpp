#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--) {
        int a, b;
        cin>>a>>b;
        int mini = min(a, b);
        int maxi = max(a, b);
        if (maxi>(2*mini)) {
            cout<<"NO\n";
        }
        else {
            if ((a+b)%3==0) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}