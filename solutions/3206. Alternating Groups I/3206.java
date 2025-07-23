class Solution {
  public int numberOfAlternatingGroups(int[] colors) {
    final int n = colors.length;
    int ans = 0;

    for (int i = 0; i < n; ++i)
      if (colors[i] != colors[(i - 1 + n) % n] && colors[i] != colors[(i + 1) % n])
        ++ans;

    return ans;
  }
}
