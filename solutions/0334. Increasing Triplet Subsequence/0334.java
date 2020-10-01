class Solution {
  public boolean increasingTriplet(int[] nums) {
    int first = Integer.MAX_VALUE;
    int second = Integer.MAX_VALUE;

    for (final int num : nums)
      if (num <= first)
        first = num;
      else if (num <= second) // first < num <= second
        second = num;
      else // first < second < num (third)
        return true;

    return false;
  }
}