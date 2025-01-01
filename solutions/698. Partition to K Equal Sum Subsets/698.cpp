class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0)
      return false;

    const int target = sum / k;  // the target sum of each subset
    if (ranges::any_of(nums, [target](const int num) { return num > target; }))
      return false;

    ranges::sort(nums, greater<>());
    return dfs(nums, 0, k, /*currSum=*/0, target, /*used=*/0);
  }

 private:
  bool dfs(const vector<int>& nums, int s, int remainingGroups, int currSum,
           const int subsetTargetSum, int used) {
    if (remainingGroups == 0)
      return true;
    if (currSum > subsetTargetSum)
      return false;
    if (currSum == subsetTargetSum)  // Find a valid group, so fresh start.
      return dfs(nums, 0, remainingGroups - 1, 0, subsetTargetSum, used);

    for (int i = s; i < nums.size(); ++i) {
      if (used >> i & 1)
        continue;
      if (dfs(nums, i + 1, remainingGroups, currSum + nums[i], subsetTargetSum,
              used | 1 << i))
        return true;
    }

    return false;
  }
};
