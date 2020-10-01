class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    const int n = stoneValue.size();

    vector<int> memo(n, INT_MIN);

    // dp(i) := max ""relative score"" Alice can make with stoneValue[i..n)
    function<int(int)> dp = [&](int i) {
      if (i == n) return 0;
      int& ans = memo[i];
      if (ans > INT_MIN) return ans;

      int sum = 0;
      for (int j = i; j < i + 3 && j < n; ++j) {
        sum += stoneValue[j];
        ans = max(ans, sum - dp(j + 1));
      }

      return ans;
    };

    const int score = dp(0);
    return score > 0 ? ""Alice"" : score < 0 ? ""Bob"" : ""Tie"";
  }
};