class Solution {
 public:
  // Main function to start the calculation
  int minCost(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> mem(n + 1, vector<int>(n + 1, -1));
    return minCost(/*last=*/0, 1, nums, mem);
  }

 private:
  int minCost(int last, int i, vector<int>& nums, vector<vector<int>>& mem) {
    const int n = nums.size();
    if (i == n)  // Single element left.
      return nums[last];
    if (i == n - 1)  // Two elements left.
      return max(nums[last], nums[i]);
    if (mem[i][last] != -1)
      return mem[i][last];
    const int a = max(nums[i], nums[i + 1]) + minCost(last, i + 2, nums, mem);
    const int b = max(nums[last], nums[i]) + minCost(i + 1, i + 2, nums, mem);
    const int c = max(nums[last], nums[i + 1]) + minCost(i, i + 2, nums, mem);
    return mem[i][last] = min({a, b, c});
  }
};
