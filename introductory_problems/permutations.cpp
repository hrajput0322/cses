#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if (n==1) {
        cout<<1;
        return 0;
    }
    vector<int> ans;
    for (int i=2; i<=n; i+=2) {
        ans.push_back(i);
    }
    for (int i=1; i<=n; i+=2) {
        if (abs(i-ans.back())==1) {
            cout<<"NO SOLUTION";
            return 0;
        }
        ans.push_back(i);
    }

    for (auto it: ans) {
        cout<<it<<" ";
    }
    return 0;
}