class Solution {
 public:
  int houseOfCards(int n) {
    // dp[i] := # of valid result for i cards
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int baseCards = 2; baseCards <= n; baseCards += 3)
      for (int i = n; i >= baseCards; --i)
        // Use `baseCards` as the base, so we're left w/ `i - baseCards` cards.
        dp[i] += dp[i - baseCards];

    return dp[n];
  }
};
