class Solution {
 public:
  int specialPerm(vector<int>& nums) {
    const int n = nums.size();
    const int maxMask = 1 << n;
    int ans = 0;
    vector<vector<int>> mem(n, vector<int>(maxMask));

    for (int i = 0; i < n; ++i) {
      ans += specialPerm(nums, i, 1 << i, maxMask, mem);
      ans %= kMod;
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of special permutations, where the previous number is
  // nums[i] and `mask` is the bitmask of the used numbers.
  int specialPerm(const vector<int>& nums, int prev, int mask,
                  const int& maxMask, vector<vector<int>>& mem) {
    if (mask == maxMask - 1)
      return 1;
    if (mem[prev][mask] > 0)
      return mem[prev][mask];

    int res = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (mask >> i & 1)
        continue;
      if (nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0) {
        res += specialPerm(nums, i, mask | 1 << i, maxMask, mem);
        res %= kMod;
      }
    }

    return mem[prev][mask] = res;
  }
};
