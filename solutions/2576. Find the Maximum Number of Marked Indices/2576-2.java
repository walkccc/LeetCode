class Solution {
  public int maxNumOfMarkedIndices(int[] nums) {
    Arrays.sort(nums);

    int i = 0;
    for (int j = nums.length / 2; j < nums.length; ++j)
      if (2 * nums[i] <= nums[j] && ++i == nums.length / 2)
        break;

    return i * 2;
  }
}
