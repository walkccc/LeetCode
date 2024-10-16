class Solution {
 public:
  int sumOfPower(vector<int>& nums, int k) {
    vector<vector<int>> mem(nums.size(), vector<int>(k + 1, -1));
    return sumOfPower(nums, 0, k, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of subsequences in nums[i..n) that sums to j.
  int sumOfPower(const vector<int>& nums, int i, int j,
                 vector<vector<int>>& mem) {
    if (j == 0)
      // For each of the remaining number, we can either pick it or skip it.
      return modPow(2, nums.size() - i);
    if (i == nums.size() || j < 0)
      return 0;
    if (mem[i][j] != -1)
      return mem[i][j];
    // 1. Include nums[i] in the subsequence and pick it.
    // 2. Include nums[i] in the subsequence and skip it.
    // 3. Exclude nums[i] in the subsequence.
    return mem[i][j] = (sumOfPower(nums, i + 1, j - nums[i], mem) +
                        2L * sumOfPower(nums, i + 1, j, mem)) %
                       kMod;
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
