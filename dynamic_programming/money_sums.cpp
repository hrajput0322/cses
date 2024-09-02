#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> sums;
    vector<int> coins(n);
    for (int i=0; i<n; i++) {
        cin>>coins[i];
    }
    sums.insert(coins[0]);
    for (int i=1; i<n; i++) {
        set<int> temp;
        for (auto it: sums) {
            temp.insert(it+coins[i]);
        }
        for (auto it: temp) {
            sums.insert(it);
        }
        sums.insert(coins[i]);
    }

    cout<<sums.size()<<"\n";
    for (auto it: sums) {
        cout<<it<<" ";
    }
    return 0;
}