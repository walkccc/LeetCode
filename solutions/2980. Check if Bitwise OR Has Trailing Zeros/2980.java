class Solution {
  public boolean hasTrailingZeros(int[] nums) {
    int countEven = 0;

    for (final int num : nums)
      if (num % 2 == 0)
        ++countEven;

    return countEven >= 2;
  }
}
