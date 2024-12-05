class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> mem(n + 2, vector<int>(n + 2));
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    return maxCoins(nums, 1, n, mem);
  }

 private:
  // Returns maxCoins(nums[i..j]).
  int maxCoins(const vector<int>& nums, int i, int j,
               vector<vector<int>>& mem) {
    if (i > j)
      return 0;
    if (mem[i][j] > 0)
      return mem[i][j];

    for (int k = i; k <= j; ++k)
      mem[i][j] = max(mem[i][j], maxCoins(nums, i, k - 1, mem) +
                                     maxCoins(nums, k + 1, j, mem) +
                                     nums[i - 1] * nums[k] * nums[j + 1]);

    return mem[i][j];
  }
};
