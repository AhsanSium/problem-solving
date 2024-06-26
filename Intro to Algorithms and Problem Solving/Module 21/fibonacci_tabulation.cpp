#include<bits/stdc++.h>
using namespace std;
const int N = 101;
/*
 - 1. Define state: fib(n) -> calculates the n'th fibonacci number
 - 2. Recursive Equation: fib(n - 1) + fib(n - 2)
 - 3. Base case: fib(1) = 1, fib(2) = 1
*/

long long dp[N];

int main()
{
    int n;
    cin >> n;

    // 1. handle base case
    dp[1] = 1;
    dp[2] = 1;

    // 2. Loop through the states
    for(int i = 3; i <= n; i++){
        // 2.1. calculate the answer from smaller sub problems
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << "\n";

    return 0;
}
