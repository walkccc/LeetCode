class Solution {
 public:
  int minArraySum(vector<int>& nums, int k, int op1, int op2) {
    vector<vector<vector<int>>> mem(
        nums.size(),
        vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, INT_MAX)));
    return minArraySum(nums, 0, op1, op2, k, mem);
  }

 private:
  // Returns the minimum sum of nums[i..n - 1] with `op1` operations of op1 and
  // `op2` operations of op2.
  int minArraySum(const vector<int>& nums, int i, int op1, int op2, int k,
                  vector<vector<vector<int>>>& mem) {
    if (i == nums.size())
      return 0;
    if (mem[i][op1][op2] != INT_MAX)
      return mem[i][op1][op2];
    int res = nums[i] + minArraySum(nums, i + 1, op1, op2, k, mem);
    if (op1 > 0)
      res = min(res, (nums[i] + 1) / 2 +
                         minArraySum(nums, i + 1, op1 - 1, op2, k, mem));
    if (op2 > 0 && nums[i] >= k)
      res = min(res,
                nums[i] - k + minArraySum(nums, i + 1, op1, op2 - 1, k, mem));
    if (op1 > 0 && op2 > 0) {
      if ((nums[i] + 1) / 2 >= k)
        res = min(res, (nums[i] + 1) / 2 - k +
                           minArraySum(nums, i + 1, op1 - 1, op2 - 1, k, mem));
      if (nums[i] >= k)
        res = min(res, (nums[i] - k + 1) / 2 +
                           minArraySum(nums, i + 1, op1 - 1, op2 - 1, k, mem));
    }
    return mem[i][op1][op2] = res;
  }
};
