class Solution {
  public int[] pourWater(int[] heights, int V, int K) {
    final int n = heights.length;

    int i = K;
    while (V-- > 0) {
      while (i > 0 && heights[i] >= heights[i - 1])
        --i;
      while (i + 1 < n && heights[i] >= heights[i + 1])
        ++i;
      while (i > K && heights[i] == heights[i - 1])
        --i;
      ++heights[i];
    }

    return heights;
  }
}
