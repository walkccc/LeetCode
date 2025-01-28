class Solution {
 public:
  int maxScore(vector<int>& nums) {
    const int n = nums.size() / 2;
    vector<vector<int>> mem(n + 1, vector<int>(1 << n * 2));
    return maxScore(nums, 1, 0, mem);
  }

 private:
  // Returns the maximum score you can receive after performing the k to n
  // operations, where `mask` is the bitmask of the chosen numbers.
  int maxScore(const vector<int>& nums, int k, int mask,
               vector<vector<int>>& mem) {
    if (k == mem.size())
      return 0;
    if (mem[k][mask] > 0)
      return mem[k][mask];

    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j) {
        const int chosenMask = 1 << i | 1 << j;
        if ((mask & chosenMask) == 0)
          mem[k][mask] = max(mem[k][mask],
                             k * __gcd(nums[i], nums[j]) +
                                 maxScore(nums, k + 1, mask | chosenMask, mem));
      }

    return mem[k][mask];
  }
};
