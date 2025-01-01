class Solution {
  public int minTaps(int n, int[] ranges) {
    int[] nums = new int[n + 1];

    for (int i = 0; i <= n; ++i) {
      int l = Math.max(0, i - ranges[i]);
      int r = Math.min(n, i + ranges[i]);
      nums[l] = Math.max(nums[l], r - l);
    }

    int ans = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i < n; i++) {
      farthest = Math.max(farthest, i + nums[i]);
      if (i == end) {
        ++ans;
        end = farthest;
      }
    }

    return end == n ? ans : -1;
  }
}
