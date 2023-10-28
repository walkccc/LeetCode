class Solution {
  public int sumOfFlooredPairs(int[] nums) {
    final int kMod = 1_000_000_007;
    final int kMax = Arrays.stream(nums).max().getAsInt();
    long ans = 0;
    // count[i] := # of nums <= i
    int[] count = new int[kMax + 1];

    for (final int num : nums)
      ++count[num];

    for (int i = 1; i <= kMax; ++i)
      count[i] += count[i - 1];

    for (int i = 1; i <= kMax; ++i)
      if (count[i] > count[i - 1]) {
        long sum = 0;
        for (int j = 1; i * j <= kMax; ++j) {
          final int lo = i * j - 1;
          final int hi = i * (j + 1) - 1;
          sum += (count[Math.min(hi, kMax)] - count[lo]) * (long) j;
        }
        ans += sum * (count[i] - count[i - 1]);
        ans %= kMod;
      }

    return (int) ans;
  }
}
