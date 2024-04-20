class Solution {
  public int countSubarrays(int[] nums, int k) {
    final int kIndex = find(nums, k);
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int i = kIndex, balance = 0; i >= 0; --i) {
      if (nums[i] < k)
        --balance;
      else if (nums[i] > k)
        ++balance;
      count.merge(balance, 1, Integer::sum);
    }

    for (int i = kIndex, balance = 0; i < nums.length; ++i) {
      if (nums[i] < k)
        --balance;
      else if (nums[i] > k)
        ++balance;
      // The subarray that has balance == 0 or 1 having median equal to k.
      // So, add count[0 - balance] and count[1 - balance] to `ans`.
      ans += count.getOrDefault(-balance, 0) + count.getOrDefault(1 - balance, 0);
    }

    return ans;
  }

  private int find(int[] nums, int k) {
    for (int i = 0; i < nums.length; ++i)
      if (nums[i] == k)
        return i;
    throw new IllegalArgumentException();
  }
}
