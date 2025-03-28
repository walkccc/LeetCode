class Solution {
  public int smallestDivisor(int[] nums, int threshold) {
    int l = 1;
    int r = Arrays.stream(nums).max().getAsInt();

    while (l < r) {
      final int m = (l + r) / 2;
      if (sumDivision(nums, m) <= threshold)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int sumDivision(int[] nums, int m) {
    int sum = 0;
    for (final int num : nums)
      sum += (num - 1) / m + 1;
    return sum;
  }
}
