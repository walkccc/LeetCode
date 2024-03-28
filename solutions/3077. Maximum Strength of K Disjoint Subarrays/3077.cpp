class Solution {
 public:
  long long maximumStrength(vector<int>& nums, int k) {
    vector<vector<vector<long long>>> mem(
        nums.size(),
        vector<vector<long long>>(k + 1, vector<long long>(2, -1)));
    return maximumStrength(nums, 0, k, /*fresh=*/true, mem);
  }

 private:
  static constexpr long long kMin = LLONG_MIN / 2;

  // Returns the maximum strength of nums[i..n) with k operations left, where
  // `fresh` means we're starting a new subarray.
  long long maximumStrength(const vector<int>& nums, int i, int k, bool fresh,
                            vector<vector<vector<long long>>>& mem) {
    if (nums.size() - i < k)
      return kMin;
    if (k == 0)
      return 0;
    if (i == nums.size())
      return k == 0 ? 0 : kMin;
    if (mem[i][k][fresh] != -1)
      return mem[i][k][fresh];
    // If it's not fresh, we can't skip the current number and consider it as a
    // fresh start, since the case where it's fresh is already covered by
    // `includeAndFreshStart`.
    const long long skip =
        fresh ? maximumStrength(nums, i + 1, k, true, mem) : kMin;
    const long long gain = (k % 2 == 1 ? 1 : -1) * 1LL * nums[i] * k;
    const long long includeAndContinue =
        maximumStrength(nums, i + 1, k, false, mem) + gain;
    const long long includeAndFreshStart =
        maximumStrength(nums, i + 1, k - 1, true, mem) + gain;
    return mem[i][k][fresh] =
               max(skip, max(includeAndContinue, includeAndFreshStart));
  }
};
