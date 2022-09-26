class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    if (sum % k != 0)
      return false;

    const int t = sum / k;  // each subset's target sum
    return dfs(nums, 0, k, t, t, vector<bool>(nums.size()));
  }

 private:
  bool dfs(const vector<int>& nums, int s, int k, int target,
           const int subsetTargetSum, vector<bool>&& seen) {
    if (k == 0)
      return true;
    if (target < 0)
      return false;
    if (target == 0)
      return dfs(nums, 0, k - 1, subsetTargetSum, subsetTargetSum, move(seen));

    for (int i = s; i < nums.size(); ++i) {
      if (seen[i])
        continue;
      seen[i] = true;
      if (dfs(nums, i + 1, k, target - nums[i], subsetTargetSum, move(seen)))
        return true;
      seen[i] = false;
    }

    return false;
  }
};
