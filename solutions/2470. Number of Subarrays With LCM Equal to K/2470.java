class Solution {
  public int subarrayLCM(int[] nums, int k) {
    int ans = 0;

    for (int i = 0; i < nums.length; ++i) {
      int runningLcm = nums[i];
      for (int j = i; j < nums.length; ++j) {
        runningLcm = lcm(runningLcm, nums[j]);
        if (runningLcm > k)
          break;
        if (runningLcm == k)
          ++ans;
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
