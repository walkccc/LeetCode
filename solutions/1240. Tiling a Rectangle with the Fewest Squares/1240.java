class Solution {
  public int tilingRectangle(int n, int m) {
    return tilingRectangle(n, m, 0, new int[m]);
  }

  private static final int kBase = 13;
  private Map<Long, Integer> dp = new HashMap<>();

  private int tilingRectangle(int n, int m, long hashedHeights, int[] heights) {
    if (dp.containsKey(hashedHeights))
      return dp.get(hashedHeights);

    final int minHeight = Arrays.stream(heights).min().getAsInt();
    if (minHeight == n) // all filled
      return 0;

    int ans = m * n;
    int start = -1;

    for (int i = 0; i < m; ++i)
      if (heights[i] == minHeight) {
        start = i;
        break;
      }

    // try to put square of different size that doesn't exceed the width/height
    for (int sz = 1; sz <= Math.min(m - start, n - minHeight); ++sz) {
      // heights[start:start + sz] must has the same height
      if (heights[start + sz - 1] != minHeight)
        break;
      // put a square of size `sz` to cover heights[start:start + sz]
      for (int i = start; i < start + sz; ++i)
        heights[i] += sz;
      ans = Math.min(ans, tilingRectangle(n, m, hash(heights), heights));
      for (int i = start; i < start + sz; ++i)
        heights[i] -= sz;
    }

    dp.put(hashedHeights, 1 + ans);
    return 1 + ans;
  }

  private long hash(int[] heights) {
    long hashed = 0;
    for (int i = heights.length - 1; i >= 0; --i)
      hashed = hashed * kBase + heights[i];
    return hashed;
  }
}
