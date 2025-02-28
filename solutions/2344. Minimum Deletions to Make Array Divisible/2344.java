class Solution {
  public int minOperations(int[] nums, int[] numsDivide) {
    final int gcd = getGCD(numsDivide);

    Arrays.sort(nums);

    for (int i = 0; i < nums.length; ++i)
      if (gcd % nums[i] == 0)
        return i;

    return -1;
  }

  private int getGCD(int[] nums) {
    int g = nums[0];
    for (final int num : nums)
      g = gcd(g, num);
    return g;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
