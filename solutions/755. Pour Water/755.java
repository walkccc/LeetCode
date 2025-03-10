class Solution {
  public int[] pourWater(int[] heights, int volume, int k) {
    int i = k;

    while (volume-- > 0) {
      while (i > 0 && heights[i] >= heights[i - 1])
        --i;
      while (i + 1 < heights.length && heights[i] >= heights[i + 1])
        ++i;
      while (i > k && heights[i] == heights[i - 1])
        --i;
      ++heights[i];
    }

    return heights;
  }
}
