class Solution {
 public:
  int countSpecialSubsequences(vector<int>& nums) {
    vector<vector<int>> mem(nums.size(), vector<int>(4, -1));
    return countSpecialSubsequences(nums, 0, -1, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of increasing subsequences of the first i numbers, where
  // the previous number is `prev`.
  int countSpecialSubsequences(const vector<int>& nums, int i, int prev,
                               vector<vector<int>>& mem) {
    if (i == nums.size())
      return prev == 2;
    const int j = prev + 1;  // Map -1/0/1/2 to 0/1/2/3 respectively.
    if (mem[i][j] != -1)
      return mem[i][j];

    long res = 0;

    // Don't include `nums[i]`.
    res += countSpecialSubsequences(nums, i + 1, prev, mem);

    // Include `nums[i]`.
    if (nums[i] == prev)
      res += countSpecialSubsequences(nums, i + 1, prev, mem);
    if (prev == -1 && nums[i] == 0)
      res += countSpecialSubsequences(nums, i + 1, 0, mem);
    if (prev == 0 && nums[i] == 1)
      res += countSpecialSubsequences(nums, i + 1, 1, mem);
    if (prev == 1 && nums[i] == 2)
      res += countSpecialSubsequences(nums, i + 1, 2, mem);

    res %= kMod;
    return mem[i][j] = res;
  }
};
