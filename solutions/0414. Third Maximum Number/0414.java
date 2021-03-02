public class Solution {
  public int thirdMax(int[] nums) {
    long max1 = Long.MIN_VALUE; // the maximum
    long max2 = Long.MIN_VALUE; // 2nd maximum
    long max3 = Long.MIN_VALUE; // 3rd maximum

    for (final int num : nums)
      if (num > max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      } else if (max1 > num && num > max2) {
        max3 = max2;
        max2 = num;
      } else if (max2 > num && num > max3) {
        max3 = num;
      }

    return max3 == Long.MIN_VALUE ? (int) max1 : (int) max3;
  }
}
