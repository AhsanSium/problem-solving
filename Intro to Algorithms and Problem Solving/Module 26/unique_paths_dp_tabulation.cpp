// leetcode unique paths
#include<bits/stdc++.h>
using namespace std;
/*
    - state: f(n, m) -> no of unique paths from (0, 0) to (n, m)
    - recurrance: f(n, m) -> f(n - 1, m) + f(n, m - 1)
    - base case: f(0, 0) = 1
*/

const int N = 101;
int dp[N][N];

/*
3 7
28
*/

int main()
{
    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            dp[i][j] = -1;
        }
    }

    // 1. define base case
    dp[0][0] = 1;

    // 2. loop over the states
    for(int i = 0; i<= row; i++){
        for(int j = 0; j <= col; j++){
            // 2.1 calculate the ans from sub problems
            if(i == 0 && j == 0) continue;

            int ans = 0;
            if(i > 0) ans += dp[i - 1][j];
            if(j > 0) ans += dp[i][j - 1];
            dp[i][j] = ans;
        }
    }

    cout << dp[row - 1][col - 1] << "\n";

    return 0;
}

