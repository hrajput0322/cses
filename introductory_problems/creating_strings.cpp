#include<bits/stdc++.h>
using namespace std;

void solve(string &temp, string &s, set<string> &ans, vector<int> &visited, int n) {
    if (temp.size()==n) {
        ans.insert(temp);
        return;
    }

    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            temp.push_back(s[i]);
            visited[i] = 1;
            solve(temp, s, ans, visited, n);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main(){
    string s;
    cin>>s;
    string temp = "";
    vector<int> visited(s.size(), 0);
    set<string> ans;
    solve(temp, s, ans, visited, s.size());
    cout<<ans.size()<<"\n";
    for (auto it: ans) {
        cout<<it<<"\n";
    }
    return 0;
}