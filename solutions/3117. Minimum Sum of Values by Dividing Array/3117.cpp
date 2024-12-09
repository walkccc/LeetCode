class Solution {
 public:
  int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
    vector<vector<unordered_map<int, int>>> mem(
        nums.size(), vector<unordered_map<int, int>>(andValues.size()));
    const int ans = minimumValueSum(nums, andValues, 0, 0, kAllMask, mem);
    return ans == kInf ? -1 : ans;
  }

 private:
  static constexpr int kInf = 1'000'000'000;
  static constexpr int kAllMask = (1 << 17) - 1;

  // Returns the minimum value sum of nums[i..n) and andValues[j..m), where
  // `mask` is the running value of the current subarray.
  int minimumValueSum(const vector<int>& nums, const vector<int>& andValues,
                      int i, int j, int mask,
                      vector<vector<unordered_map<int, int>>>& mem) {
    if (i == nums.size() && j == andValues.size())
      return 0;
    if (i == nums.size() || j == andValues.size())
      return kInf;
    if (const auto it = mem[i][j].find(mask); it != mem[i][j].cend())
      return it->second;
    mask &= nums[i];
    if (mask < andValues[j])
      return mem[i][j][mask] = kInf;
    if (mask == andValues[j])
      // 1. Keep going.
      // 2. End the subarray here and pick nums[i], then fresh start.
      return mem[i][j][mask] =
                 min(minimumValueSum(nums, andValues, i + 1, j, mask, mem),
                     nums[i] + minimumValueSum(nums, andValues, i + 1, j + 1,
                                               kAllMask, mem));
    // Keep going.
    return mem[i][j][mask] =
               minimumValueSum(nums, andValues, i + 1, j, mask, mem);
  };
};
