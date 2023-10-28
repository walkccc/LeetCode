class Solution {
  public int[] distinctNumbers(int[] nums, int k) {
    int[] ans = new int[nums.length - k + 1];
    int distinct = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      if (count.merge(nums[i], 1, Integer::sum) == 1)
        ++distinct;
      if (i >= k && count.merge(nums[i - k], -1, Integer::sum) == 0)
        --distinct;
      if (i >= k - 1)
        ans[i - k + 1] = distinct;
    }

    return ans;
  }
}
