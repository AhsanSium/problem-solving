#include<bits/stdc++.h>
using namespace std;

/*
    -state: LCS(i, j) -> Length of longest common subsequence between strings
                         s[i ... n] and t[j ... m]

    -recurrence: if(s[i] == t[j]){return(LCS(i, j) = 1 + LCS(i-1, j-1))}
                 else {return(max(LCS(i-1, j), LCS(i, j-1)))}

    -base case: LCS(i, m) = 0
                LCS(n, j) = 0
*/

const int N = 3003;
int dp[N][N];
int n, m;
string s, t;

int main()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = -1;
        }
    }

    // 1. handle base case
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = 0;
    }

    // 2. loop over the states
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // 2.1 calculate ans from smaller sub problems
            if(s[i - 1] == t[j - 1]){dp[i][j] = 1 + dp[i-1][j-1];}
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}


