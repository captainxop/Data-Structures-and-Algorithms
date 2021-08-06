#include <bits/stdc++.h>
using namespace std;
#define mem0(a) memset(a, 0, sizeof(a))
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int n;
int board[15][15];

void Print()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        
        cout << '\n';
    }
    
    cout << '\n';
}

bool isPossible(int row, int col)
{
    // checks if there is already a Queen in the same column
    for (int i = row - 1; i >= 0; i--) { 
        if (board[i][col] == 1) {
            return false;
        }
    }
    
    // checks if there is already a Queen in its Upper Left Diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    // checks if there is already a Queen in its Upper Right Diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

void nQueen(int row)
{
    if (row == n) {
        Print();
        return;
    }
    
    for (int j = 0; j < n; j++) {
        if (isPossible(row, j)) {
            board[row][j] = 1;
            nQueen(row + 1);
            board[row][j] = 0;
        }
    }
}

void solve()
{
    cin >> n;
    mem0(board);
    
    nQueen(0);
}

int main()
{
    fastio;
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    
    int t=1;
    cin>>t;
    while(t--) solve();
    
    return 0;
}
