class Solution {
  public int largestSumAfterKNegations(int[] nums, int k) {
    Arrays.sort(nums);

    for (int i = 0; i < nums.length; ++i) {
      if (nums[i] > 0 || k == 0)
        break;
      nums[i] = -nums[i];
      --k;
    }

    return Arrays.stream(nums).sum() - (k % 2) * Arrays.stream(nums).min().getAsInt() * 2;
  }
}
