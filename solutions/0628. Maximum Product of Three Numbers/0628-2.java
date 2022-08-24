class Solution {
  public int maximumProduct(int[] nums) {
    int min1 = Integer.MAX_VALUE; // the minimum
    int min2 = Integer.MAX_VALUE; // 2nd minimum
    int max1 = Integer.MIN_VALUE; // the maximum
    int max2 = Integer.MIN_VALUE; // 2nd maximum
    int max3 = Integer.MIN_VALUE; // 3rd maximum

    for (final int num : nums) {
      if (num <= min1) {
        min2 = min1;
        min1 = num;
      } else if (num <= min2) {
        min2 = num;
      }
      if (num >= max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      } else if (num >= max2) {
        max3 = max2;
        max2 = num;
      } else if (num >= max3) {
        max3 = num;
      }
    }

    return max(max1 * min1 * min2, max1 * max2 * max3);
  }
}
