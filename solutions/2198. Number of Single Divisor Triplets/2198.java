class Solution {
  public long singleDivisorTriplet(int[] nums) {
    final int kMax = 100;
    long ans = 0;
    int[] count = new int[kMax + 1];

    for (final int num : nums)
      ++count[num];

    for (int a = 1; a <= kMax; ++a)
      for (int b = a; count[a] > 0 && b <= kMax; ++b)
        for (int c = b; count[b] > 0 && c <= kMax; ++c) {
          final int sum = a + b + c;
          if (divisible(sum, a) + divisible(sum, b) + divisible(sum, c) != 1)
            continue;
          if (a == b)
            ans += (long) count[a] * (count[a] - 1) / 2 * count[c];
          else if (b == c)
            ans += (long) count[b] * (count[b] - 1) / 2 * count[a];
          else
            ans += (long) count[a] * count[b] * count[c];
        }

    return ans * 6;
  }

  private int divisible(int sum, int num) {
    return sum % num == 0 ? 1 : 0;
  }
}
