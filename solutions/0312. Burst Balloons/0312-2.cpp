class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();

    nums.insert(begin(nums), 1);
    nums.insert(end(nums), 1);

    vector<vector<int>> memo(n + 2, vector<int>(n + 2));

    function<int(int, int)> dp = [&](int i, int j) {
      if (i > j) return 0;
      int& ans = memo[i][j];
      if (ans) return ans;

      for (int k = i; k <= j; ++k)
        ans = max(ans, dp(i, k - 1) + dp(k + 1, j) +
                           nums[i - 1] * nums[k] * nums[j + 1]);

      return ans;
    };

    return dp(1, n);
  }
};