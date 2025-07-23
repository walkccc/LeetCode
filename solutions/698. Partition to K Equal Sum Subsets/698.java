class Solution {
  public boolean canPartitionKSubsets(int[] nums, int k) {
    final int sum = Arrays.stream(nums).sum();
    if (sum % k != 0)
      return false;

    final int target = sum / k; // the target sum of each subset
    if (Arrays.stream(nums).anyMatch(num -> num > target))
      return false;

    return dfs(nums, 0, k, /*currSum=*/0, target, /*used=*/0);
  }

  private boolean dfs(int[] nums, int s, int remainingGroups, int currSum, int subsetTargetSum,
                      int used) {
    if (remainingGroups == 0)
      return true;
    if (currSum > subsetTargetSum)
      return false;
    if (currSum == subsetTargetSum) // Find a valid group, so fresh start.
      return dfs(nums, 0, remainingGroups - 1, 0, subsetTargetSum, used);

    for (int i = s; i < nums.length; ++i) {
      if ((used >> i & 1) == 1)
        continue;
      if (dfs(nums, i + 1, remainingGroups, currSum + nums[i], subsetTargetSum, used | 1 << i))
        return true;
    }

    return false;
  }
}
