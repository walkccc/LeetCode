class Solution {
  public int partitionArray(int[] nums, int k) {
    Arrays.sort(nums);

    int ans = 1;
    int min = nums[0];

    for (int i = 1; i < nums.length; ++i)
      if (min + k < nums[i]) {
        ++ans;
        min = nums[i];
      }

    return ans;
  }
}
