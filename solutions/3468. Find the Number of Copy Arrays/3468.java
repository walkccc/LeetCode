class Solution {
  public int countArrays(int[] original, int[][] bounds) {
    int mn = bounds[0][0];
    int mx = bounds[0][1];

    for (int i = 1; i < original.length; ++i) {
      final int diff = original[i] - original[i - 1];
      mn = Math.max(mn + diff, bounds[i][0]);
      mx = Math.min(mx + diff, bounds[i][1]);
    }

    return Math.max(0, mx - mn + 1);
  }
}
