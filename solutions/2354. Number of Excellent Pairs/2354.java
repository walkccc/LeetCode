class Solution {
  public long countExcellentPairs(int[] nums, int k) {
    final int kMaxDigit = 30;
    // bits(num1 | num2) + bits(num1 & num2) = bits(num1) + bits(num2)
    long ans = 0;
    long[] count = new long[kMaxDigit];

    for (final int num : Arrays.stream(nums).boxed().collect(Collectors.toSet()))
      ++count[Integer.bitCount(num)];

    for (int i = 0; i < kMaxDigit; ++i)
      for (int j = 0; j < kMaxDigit; ++j)
        if (i + j >= k)
          ans += count[i] * count[j];

    return ans;
  }
}
