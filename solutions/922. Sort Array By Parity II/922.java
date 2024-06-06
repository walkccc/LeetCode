class Solution {
  public int[] sortArrayByParityII(int[] nums) {
    final int n = nums.length;

    for (int i = 0, j = 1; i < n; i += 2, j += 2) {
      while (i < n && nums[i] % 2 == 0)
        i += 2;
      while (j < n && nums[j] % 2 == 1)
        j += 2;
      if (i < n) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }

    return nums;
  }
}
