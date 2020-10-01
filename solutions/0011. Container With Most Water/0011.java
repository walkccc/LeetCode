class Solution {
  public int maxArea(int[] height) {
    int ans = 0;
    int l = 0;
    int r = height.length - 1;

    while (l < r) {
      final int h = Math.min(height[l], height[r]);
      ans = Math.max(ans, (r - l) * h);
      while (height[l] <= h && l < r)
        ++l;
      while (height[r] <= h && l < r)
        --r;
    }

    return ans;
  }
}