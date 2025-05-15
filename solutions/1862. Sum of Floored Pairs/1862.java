class Solution {
  public int sumOfFlooredPairs(int[] nums) {
    final int MOD = 1_000_000_007;
    final int MAX = Arrays.stream(nums).max().getAsInt();
    long ans = 0;
    // count[i] := the number of `nums` <= i
    int[] count = new int[MAX + 1];

    for (final int num : nums)
      ++count[num];

    for (int i = 1; i <= MAX; ++i)
      count[i] += count[i - 1];

    for (int i = 1; i <= MAX; ++i)
      if (count[i] > count[i - 1]) {
        long sum = 0;
        for (int j = 1; i * j <= MAX; ++j) {
          final int lo = i * j - 1;
          final int hi = i * (j + 1) - 1;
          sum += (count[Math.min(hi, MAX)] - count[lo]) * j;
        }
        ans += sum * (count[i] - count[i - 1]);
        ans %= MOD;
      }

    return (int) ans;
  }
}
