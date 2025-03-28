class Solution {
 public:
  long long countQuadruplets(vector<int>& nums) {
    long ans = 0;
    // dp[j] := the number of triplets (i, j, k) where i < j < k and nums[i] <
    // nums[k] < nums[j]. Keep this information for l to use later.
    vector<int> dp(nums.size());

    // k can be treated as l.
    for (int k = 2; k < nums.size(); ++k)
      // j can be treated as i.
      for (int j = 0, numLessThanK = 0; j < k; ++j)
        if (nums[j] < nums[k]) {
          ++numLessThanK;  // nums[i] < nums[k]
          // nums[j] < nums[l], so we should add dp[j] since we find a new
          // quadruplets for (i, j, k, l).
          ans += dp[j];

        } else if (nums[j] > nums[k]) {
          dp[j] += numLessThanK;
        }

    return ans;
  }
};
