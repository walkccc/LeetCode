class Solution {
  public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
    final int kMod = 1_000_000_007;
    Arrays.sort(horizontalCuts);
    Arrays.sort(verticalCuts);

    // the maximum gap of each direction
    int maxGapX = Math.max(verticalCuts[0], w - verticalCuts[verticalCuts.length - 1]);
    int maxGapY = Math.max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.length - 1]);

    for (int i = 1; i < verticalCuts.length; ++i)
      maxGapX = Math.max(maxGapX, verticalCuts[i] - verticalCuts[i - 1]);

    for (int i = 1; i < horizontalCuts.length; ++i)
      maxGapY = Math.max(maxGapY, horizontalCuts[i] - horizontalCuts[i - 1]);

    return (int) ((long) maxGapX * maxGapY % kMod);
  }
}
