class Solution {
  public int trap(int[] height) {
    final int n = height.length;

    int ans = 0;
    int[] l = new int[n]; // l[i] := max in height[0..i]
    int[] r = new int[n]; // r[i] := max in height[i..n - 1]

    for (int i = 0; i < n; ++i)
      l[i] = i == 0 ? height[i] : Math.max(height[i], l[i - 1]);

    for (int i = n - 1; i >= 0; --i)
      r[i] = i == n - 1 ? height[i] : Math.max(height[i], r[i + 1]);

    for (int i = 0; i < n; ++i)
      ans += Math.min(l[i], r[i]) - height[i];

    return ans;
  }
}