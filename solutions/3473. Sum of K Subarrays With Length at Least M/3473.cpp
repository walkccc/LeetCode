class Solution {
 public:
  int maxSum(vector<int>& nums, int k, int m) {
    const int n = nums.size();
    vector<int> prefix(n + 1);
    vector<vector<vector<int>>> mem(
        n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
    return maxSum(nums, 0, /*ongoing=*/0, k, m, prefix, mem);
  }

 private:
  static constexpr int kInf = 20'000'000;

  int maxSum(const vector<int>& nums, int i, int ongoing, int k, const int& m,
             const vector<int>& prefix, vector<vector<vector<int>>>& mem) {
    if (k < 0)
      return -kInf;
    if (i == nums.size())
      return k == 0 ? 0 : -kInf;
    if (mem[i][ongoing][k] != -1)
      return mem[i][ongoing][k];
    if (ongoing == 1)
      // 1. End the current subarray (transition to state 0, same index i)
      // 2. Extend the current subarray by picking nums[i] and move to i + 1.
      return mem[i][1][k] =
                 max(maxSum(nums, i, 0, k, m, prefix, mem),
                     maxSum(nums, i + 1, 1, k, m, prefix, mem) + nums[i]);
    // ongoing == 0
    // 1. Skip nums[i].
    // 2. Pick nums[i..i + m - 1] (only if k > 0 and there're enough elements).
    int res = maxSum(nums, i + 1, 0, k, m, prefix, mem);
    if (i + m <= nums.size())  // If we have enough elements for a new segment
      res = max(res, maxSum(nums, i + m, 1, k - 1, m, prefix, mem) +
                         (prefix[i + m] - prefix[i]));
    return mem[i][0][k] = res;
  }
};
