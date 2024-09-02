#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board) {
    if (board[row][col]=='*') {
        return false;
    }

    for (int i=0; i<8; i++) {
        if (board[i][col]=='Q') return false;
    }

    for (int j=0; j<8; j++) {
        if (board[row][j]=='Q') return false;
    }

    int i = row;
    int j = col;

    while (i>=0 && j>=0) {
        if (board[i][j]=='Q') return false;
        i--;
        j--;
    }

    i = row;
    j = col;

    while (i<8 && j>=0) {
        if (board[i][j]=='Q') return false;
        i++;
        j--;
    }

    return true;
}

void solve(int col, vector<string> &board, int &count) {
    if (col==8) {
        count++;
        return;
    }

    for (int i=0; i<8; i++) {
        if (isSafe(i, col, board)) {
            board[i][col] = 'Q';
            solve(col+1, board, count);
            board[i][col] = '.';
        }
    }
}

int main(){
    int n = 8;
    vector<string> board(n);
    for (int i=0; i<n; i++) {
        cin>>board[i];
    }
    int count = 0;
    solve(0, board, count);
    cout<<count<<"\n";
    return 0;
}