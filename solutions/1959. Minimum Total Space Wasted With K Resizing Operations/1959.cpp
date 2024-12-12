class Solution {
 public:
  int minSpaceWastedKResizing(vector<int>& nums, int k) {
    vector<vector<int>> mem(nums.size(), vector<int>(k + 1, -1));
    return minSpaceWasted(nums, 0, k, mem);
  }

 private:
  static constexpr int kMax = 200'000'000;

  // Returns the minimum space wasted for nums[i..n) if you can resize k times.
  int minSpaceWasted(const vector<int>& nums, int i, int k,
                     vector<vector<int>>& mem) {
    if (i == nums.size())
      return 0;
    if (k == -1)
      return kMax;
    if (mem[i][k] != -1)
      return mem[i][k];

    int res = kMax;
    int sum = 0;
    int maxNum = nums[i];

    for (int j = i; j < nums.size(); ++j) {
      sum += nums[j];
      maxNum = max(maxNum, nums[j]);
      const int wasted = maxNum * (j - i + 1) - sum;
      res = min(res, minSpaceWasted(nums, j + 1, k - 1, mem) + wasted);
    }

    return mem[i][k] = res;
  }
};
