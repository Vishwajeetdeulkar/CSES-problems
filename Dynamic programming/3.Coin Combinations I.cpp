#include <bits/stdc++.h>
using namespace std;

int countWays(int targetSum, vector<int>& coins, vector<int>& dp) {
    if (targetSum == 0) return 1;  // Base case: one way to make sum 0 (use no coins)
    if (targetSum < 0) return 0;   // No way to make a negative sum
    
    if (dp[targetSum] != -1) return dp[targetSum];  // Return cached result if available

    int ways = 0;
    for (int coin : coins) {
        ways += countWays(targetSum - coin, coins, dp);
    }
    
    dp[targetSum] = ways;  // Store the computed result
    return ways;
}

int countWaysToProduceSum(vector<int>& coins, int targetSum) {
    vector<int> dp(targetSum + 1, -1);  // Initialize memoization table with -1
    return countWays(targetSum, coins, dp);
}
int main() {
  int n, x;
  cin >> n >> x;
  if(x==0){
    cout<<1<<endl;
    return 0;
  }
  if(n==0){
    cout<<0<<endl;
    return 0;
  }
  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

cout<<countWaysToProduceSum(coins, x);
  return 0;
}