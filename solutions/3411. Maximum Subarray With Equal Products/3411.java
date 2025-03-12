class Solution {
  public int maxLength(int[] nums) {
    final int MAX_LCM = 36_288_000; // 10! x 10
    final int n = nums.length;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      int prod = 1;
      int l = 1;
      int g = 0;
      for (int j = i; j < n; ++j) {
        prod *= nums[j];
        if (prod > MAX_LCM)
          break;
        l = lcm(l, nums[j]);
        g = gcd(g, nums[j]);
        if (prod == l * g)
          ans = Math.max(ans, j - i + 1);
      }
    }

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  private int lcm(int a, int b) {
    return a * (b / gcd(a, b));
  }
}
