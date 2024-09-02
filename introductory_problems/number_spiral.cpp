#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--) {
        long long x, y;
        cin>>x>>y;

        long long n = max(x, y);
        long long val = n*n - (n-1);

        if (x==n && y==n) {
            cout<<val<<"\n";
        }
        else if (n&1) {
            if (x==n) {
                while (n!=y) {
                    val--;
                    n--;
                }
                cout<<val<<"\n";
            }
            else {
                while (n!=x) {
                    val++;
                    n--;
                }
                cout<<val<<"\n";
            }
        }
        else {
            if (x==n) {
                while (n!=y) {
                    val++;
                    n--;
                }
                cout<<val<<"\n";
            }
            else {
                while (n!=x) {
                    val--;
                    n--;
                }
                cout<<val<<"\n";
            }
        }
    }
    return 0;
}