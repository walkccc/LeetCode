class Solution {
  public int minPairSum(int[] nums) {
    int ans = 0;

    Arrays.sort(nums);

    for (int i = 0, j = nums.length - 1; i < j;)
      ans = Math.max(ans, nums[i++] + nums[j--]);

    return ans;
  }
}
