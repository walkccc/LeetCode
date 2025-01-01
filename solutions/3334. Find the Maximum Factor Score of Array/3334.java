class Solution {
  public long maxScore(int[] nums) {
    final int n = nums.length;
    // prefixGcd[i] := GCD of nums[0..i]
    // prefixLcm[i] := LCM of nums[0..i]
    long[][] prefix = getPrefix(nums);
    long[] prefixGcd = prefix[0];
    long[] prefixLcm = prefix[1];
    // suffixGcd[i] := GCD of nums[i..n - 1]
    // suffixLcm[i] := LCM of nums[i..n - 1]
    long[][] suffix = getSuffix(nums);
    long[] suffixGcd = suffix[0];
    long[] suffixLcm = suffix[1];
    long ans = suffixGcd[0] * suffixLcm[0];

    for (int i = 0; i < n; ++i) {
      final long gcd1 = i > 0 ? prefixGcd[i - 1] : 0;
      final long gcd2 = i + 1 < n ? suffixGcd[i + 1] : 0;
      final long lcm1 = i > 0 ? prefixLcm[i - 1] : 1;
      final long lcm2 = i + 1 < n ? suffixLcm[i + 1] : 1;
      final long score = gcd(gcd1, gcd2) * lcm(lcm1, lcm2);
      ans = Math.max(ans, score);
    }

    return ans;
  }

  // Returns the prefix GCD and LCM arrays.
  private long[][] getPrefix(int[] nums) {
    long[] prefixGcd = new long[nums.length];
    long[] prefixLcm = new long[nums.length];
    long currGcd = 0;
    long currLcm = 1;
    for (int i = 0; i < nums.length; ++i) {
      currGcd = gcd(currGcd, nums[i]);
      currLcm = lcm(currLcm, nums[i]);
      prefixGcd[i] = currGcd;
      prefixLcm[i] = currLcm;
    }
    return new long[][] {prefixGcd, prefixLcm};
  }

  // Returns the suffix GCD and LCM arrays.
  private long[][] getSuffix(int[] nums) {
    long[] suffixGcd = new long[nums.length];
    long[] suffixLcm = new long[nums.length];
    long currGcd = 0;
    long currLcm = 1;
    for (int i = nums.length - 1; i >= 0; --i) {
      currGcd = gcd(currGcd, nums[i]);
      currLcm = lcm(currLcm, nums[i]);
      suffixGcd[i] = currGcd;
      suffixLcm[i] = currLcm;
    }
    return new long[][] {suffixGcd, suffixLcm};
  }

  private long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  private long lcm(long a, long b) {
    return a * (b / gcd(a, b));
  }
}
