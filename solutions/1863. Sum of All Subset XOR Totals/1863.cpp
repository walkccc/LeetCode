class Solution {
 public:
  int subsetXORSum(vector<int>& nums) {
    return dfs(nums, 0, 0);
  }

 private:
  int dfs(const vector<int>& nums, int i, int xors) {
    if (i == nums.size())
      return xors;

    const int x = dfs(nums, i + 1, xors);
    const int y = dfs(nums, i + 1, nums[i] ^ xors);
    return x + y;
  }
};
