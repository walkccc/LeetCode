class Solution {
  public long countExcellentPairs(int[] nums, int k) {
    final int MAX_BIT = 30;
    // bits(num1 | num2) + bits(num1 & num2) = bits(num1) + bits(num2)
    long ans = 0;
    long[] count = new long[MAX_BIT];

    for (final int num : Arrays.stream(nums).boxed().collect(Collectors.toSet()))
      ++count[Integer.bitCount(num)];

    for (int i = 0; i < MAX_BIT; ++i)
      for (int j = 0; j < MAX_BIT; ++j)
        if (i + j >= k)
          ans += count[i] * count[j];

    return ans;
  }
}
