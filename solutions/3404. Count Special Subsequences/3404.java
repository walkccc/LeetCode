class Solution {
  public long numberOfSubsequences(int[] nums) {
    final int n = nums.length;
    final int mx = Arrays.stream(nums).max().getAsInt();
    long ans = 0;
    int[][] count = new int[mx + 1][mx + 1];

    // nums[p] * nums[r] == nums[q] * nums[s]
    // nums[p] / nums[q] == nums[s] / nums[r]
    for (int r = 4; r <= n - 1 - 2; ++r) {
      final int q = r - 2;
      for (int p = 0; p <= q - 2; ++p) {
        final int g = gcd(nums[p], nums[q]);
        ++count[nums[p] / g][nums[q] / g];
      }
      for (int s = r + 2; s < n; ++s) {
        final int g = gcd(nums[s], nums[r]);
        ans += count[nums[s] / g][nums[r] / g];
      }
    }

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
