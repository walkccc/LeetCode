class Solution {
  public int findMiddleIndex(int[] nums) {
    int prefix = 0;
    int suffix = Arrays.stream(nums).sum();

    for (int i = 0; i < nums.length; ++i) {
      suffix -= nums[i];
      if (prefix == suffix)
        return i;
      prefix += nums[i];
    }

    return -1;
  }
}
