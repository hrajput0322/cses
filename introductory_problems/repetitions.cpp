#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();

    if (n==1) {
        cout<<1;
        return 0;
    };

    int j=1;
    int count = 1;
    int ans = 1;

    while (j<n) {
        while (s[j]==s[j-1]) {
            count++;
            j++;
            ans = max(ans, count);
        }
        count = 1;
        j++;
    }

    cout<<ans;
    return 0;
}