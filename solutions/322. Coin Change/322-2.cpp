class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // dp[i] := the minimum number of coins to make up i
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
      for (const int coin : coins)
        if (coin <= i)
          dp[i] = min(dp[i], dp[i - coin] + 1);

    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};
