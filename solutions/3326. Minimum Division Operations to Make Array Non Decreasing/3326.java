class Solution {
  public int minOperations(int[] nums) {
    int ans = 0;

    for (int i = nums.length - 2; i >= 0; --i)
      if (nums[i] > nums[i + 1]) {
        final int minDivisor = getMinDivisor(nums[i]);
        if (minDivisor > nums[i + 1])
          return -1;
        nums[i] = minDivisor;
        ++ans;
      }

    return ans;
  }

  private int getMinDivisor(int num) {
    for (int divisor = 2; divisor <= Math.sqrt(num); ++divisor)
      if (num % divisor == 0)
        return divisor;
    return num;
  }
}
