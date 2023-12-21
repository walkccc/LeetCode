class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    // dp[i] := the maximum relative score Alice can make with stoneValue[i..n)
    dp.resize(stoneValue.size(), INT_MIN);
    const int score = stoneGameIII(stoneValue, 0);
    return score > 0 ? "Alice" : score < 0 ? "Bob" : "Tie";
  }

 private:
  vector<int> dp;

  int stoneGameIII(const vector<int>& stoneValue, int i) {
    if (i == stoneValue.size())
      return 0;
    if (dp[i] > INT_MIN)
      return dp[i];

    int sum = 0;
    for (int j = i; j < i + 3 && j < stoneValue.size(); ++j) {
      sum += stoneValue[j];
      dp[i] = max(dp[i], sum - stoneGameIII(stoneValue, j + 1));
    }

    return dp[i];
  };
};
