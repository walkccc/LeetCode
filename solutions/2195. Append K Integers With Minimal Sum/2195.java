class Solution {
  public long minimalKSum(int[] nums, int k) {
    long ans = 0;
    Arrays.sort(nums);

    if (nums[0] > 1) {
      final int l = 1;
      final int r = Math.min(k, nums[0] - 1);
      ans += (long) (l + r) * (r - l + 1) / 2;
      k -= r - l + 1;
      if (k == 0)
        return ans;
    }

    for (int i = 0; i + 1 < nums.length; ++i) {
      if (nums[i] == nums[i + 1])
        continue;
      final int l = nums[i] + 1;
      final int r = Math.min(nums[i] + k, nums[i + 1] - 1);
      ans += (long) (l + r) * (r - l + 1) / 2;
      k -= r - l + 1;
      if (k == 0)
        return ans;
    }

    if (k > 0) {
      final int l = nums[nums.length - 1] + 1;
      final int r = nums[nums.length - 1] + k;
      ans += (long) (l + r) * (r - l + 1) / 2;
    }

    return ans;
  }
}
