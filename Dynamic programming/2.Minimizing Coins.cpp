#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, int x, vector<int>& coins) {
    // Step 1: Initialize the dp array with a large value (INT_MAX)
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;  // It takes 0 coins to make the sum 0

    // Step 2: Fill the dp array
    for (int i = 1; i <= x; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // Step 3: Return the result
    return dp[x] == INT_MAX ? -1 : dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int result = minCoins(n, x, coins);
    cout << result << endl;
    return 0;
}
