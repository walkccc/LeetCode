class Solution {
  public int subarraySum(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int[] prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + nums[i];

    for (int i = 0; i < n; ++i)
      ans += prefix[i + 1] - prefix[Math.max(0, i - nums[i])];

    return ans;
  }
}
