#include<bits/stdc++.h>
using namespace std;

void solve(int n, int left, int right, int middle, vector<string> &ans) {
    if (n==1) {
        ans.push_back(to_string(left) + " " + to_string(right));
        return;
    }
    solve(n-1, left, middle, right, ans);
    ans.push_back(to_string(left) + " " + to_string(right));
    solve(n-1, middle, right, left, ans);
}

int main(){
    int n;
    cin>>n;
    vector<string> ans;
    solve(n, 1, 3, 2, ans);
    cout<<ans.size()<<"\n";
    for (auto s: ans) {
        cout<<s<<"\n";
    }
    return 0;
}