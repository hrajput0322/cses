#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long sum = 1LL*n*(n+1)/2;
    if (sum&1) {
        cout<<"NO\n";
    }
    else {
        vector<int> set1;
        vector<int> set2;
        long long mid = sum/2;
        for (int i=n; i>=1; i--) {
            if (i<=mid) {
                set1.push_back(i);
                mid = mid-i;
            }
            else {
                set2.push_back(i);
            }
        }
        cout<<"YES\n";
        cout<<set1.size()<<"\n";
        for (auto it: set1) {
            cout<<it<<" ";
        }
        cout<<"\n";
        cout<<set2.size()<<"\n";
        for (auto it: set2) {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}