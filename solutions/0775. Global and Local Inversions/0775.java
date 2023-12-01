class Solution {
  public boolean isIdealPermutation(int[] nums) {
    int max = -1; // the number that is most likely > nums[i + 2]

    for (int i = 0; i + 2 < nums.length; ++i) {
      max = Math.max(max, nums[i]);
      if (max > nums[i + 2])
        return false;
    }

    return true;
  }
}
