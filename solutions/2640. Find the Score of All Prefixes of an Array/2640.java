class Solution {
  public long[] findPrefixScore(int[] nums) {
    long[] ans = new long[nums.length];
    long prefix = 0;
    int max = 0;

    for (int i = 0; i < nums.length; i++) {
      max = Math.max(max, nums[i]);
      prefix += nums[i] + max;
      ans[i] = prefix;
    }

    return ans;
  }
}
