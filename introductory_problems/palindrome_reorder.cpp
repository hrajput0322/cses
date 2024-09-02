#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char, int> m;
    string s;
    cin>>s;
    string ans = s;
    char odd_char;
    for (auto c: s) {
        m[c]++;
    }
    int count = 0;
    for (auto it: m) {
        if (it.second%2==1) {
            odd_char = it.first;
            count++;
        }
    }
    int i = 0;
    if (count>1 || (count==1 && s.length()%2==0)) {
        cout<<"NO SOLUTION\n";
    }
    else {
        int i = 0;
        int j = s.length()-1;
        for (auto it: m) {
            for (int k=0; k<it.second/2; k++) {
                ans[i] = it.first;
                ans[j] = it.first;
                i++;
                j--;
            }
        }
        if (s.length()%2==1) {
            ans[s.length()/2] = odd_char;
        }
        cout<<ans<<"\n";
    }
    return 0;
}