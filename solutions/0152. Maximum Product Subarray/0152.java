class Solution {
  public int maxProduct(int[] nums) {
    int ans = nums[0];
    int dpMin = nums[0]; // min so far
    int dpMax = nums[0]; // max so far

    for (int i = 1; i < nums.length; ++i) {
      final int num = nums[i];
      final int prevMin = dpMin; // dpMin[i - 1]
      final int prevMax = dpMax; // dpMax[i - 1]
      if (num < 0) {
        dpMin = Math.min(prevMax * num, num);
        dpMax = Math.max(prevMin * num, num);
      } else {
        dpMin = Math.min(prevMin * num, num);
        dpMax = Math.max(prevMax * num, num);
      }
      ans = Math.max(ans, dpMax);
    }

    return ans;
  }
}
