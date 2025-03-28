class Solution {
  public int countValidSelections(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int[] prefix = new int[n]; // sum(nums[0..i - 1])
    int[] suffix = new int[n]; // sum(nums[i + 1..n - 1])

    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] + nums[i - 1];

    for (int i = n - 2; i >= 0; --i)
      suffix[i] = suffix[i + 1] + nums[i + 1];

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0)
        continue;
      if (prefix[i] == suffix[i])
        ans += 2; // Go to either direction.
      if (Math.abs(prefix[i] - suffix[i]) == 1)
        ans += 1; // Go to the direction with the larger sum.
    }

    return ans;
  }
}
