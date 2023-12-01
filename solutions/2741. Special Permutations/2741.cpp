class Solution {
 public:
  int specialPerm(vector<int>& nums) {
    const int n = nums.size();
    const int maxMask = 1 << n;
    int ans = 0;
    // dp[i][j] := the number of special permutations, where the previous number
    // is nums[i] and bitmask j represents the used numbers
    dp.resize(n, vector<int>(maxMask));

    for (int i = 0; i < n; ++i) {
      ans += specialPerm(nums, i, 1 << i, maxMask);
      ans %= kMod;
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<int>> dp;

  int specialPerm(const vector<int>& nums, int prev, int mask,
                  const int& maxMask) {
    if (mask == maxMask - 1)
      return 1;
    if (dp[prev][mask] > 0)
      return dp[prev][mask];

    int res = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (mask >> i & 1)
        continue;
      if (nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0) {
        res += specialPerm(nums, i, mask | 1 << i, maxMask);
        res %= kMod;
      }
    }

    return dp[prev][mask] = res;
  }
};
