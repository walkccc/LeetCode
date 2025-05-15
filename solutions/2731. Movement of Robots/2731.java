class Solution {
  public int sumDistance(int[] nums, String s, int d) {
    final int MOD = 1_000_000_007;
    final int n = nums.length;
    int ans = 0;
    int prefix = 0;
    int[] pos = new int[n];

    for (int i = 0; i < n; ++i)
      if (s.charAt(i) == 'L')
        pos[i] = nums[i] - d;
      else
        pos[i] = nums[i] + d;

    Arrays.sort(pos);

    for (int i = 0; i < n; ++i) {
      ans = (int) (((ans + 1L * i * pos[i] - prefix) % MOD + MOD) % MOD);
      prefix = (int) (((0L + prefix + pos[i]) % MOD + MOD) % MOD);
    }

    return ans;
  }
}
