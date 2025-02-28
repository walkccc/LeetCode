class Solution {
  public List<Integer> shortestDistanceColor(int[] colors, int[][] queries) {
    final int kNumColor = 3;
    final int n = colors.length;
    List<Integer> ans = new ArrayList<>();
    // left[i][c] := the closest index of color c in index i to the left
    int[][] left = new int[n][kNumColor + 1];
    // right[i][c] := the closest index of color c in index i to the right
    int[][] right = new int[n][kNumColor + 1];

    int[] colorToClosestIndex = {0, -1, -1, -1}; // 0-indexed, -1 := N/A
    for (int i = 0; i < n; ++i) {
      colorToClosestIndex[colors[i]] = i;
      for (int c = 1; c <= kNumColor; ++c)
        left[i][c] = colorToClosestIndex[c];
    }

    colorToClosestIndex = new int[] {0, -1, -1, -1}; // Reset
    for (int i = n - 1; i >= 0; --i) {
      colorToClosestIndex[colors[i]] = i;
      for (int c = 1; c <= kNumColor; ++c)
        right[i][c] = colorToClosestIndex[c];
    }

    for (int[] query : queries) {
      final int i = query[0];
      final int c = query[1];
      final int leftDist = left[i][c] == -1 ? Integer.MAX_VALUE : i - left[i][c];
      final int rightDist = right[i][c] == -1 ? Integer.MAX_VALUE : right[i][c] - i;
      final int minDist = Math.min(leftDist, rightDist);
      ans.add(minDist == Integer.MAX_VALUE ? -1 : minDist);
    }

    return ans;
  }
}
