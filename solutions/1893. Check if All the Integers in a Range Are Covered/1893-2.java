class Solution {
  public boolean isCovered(int[][] ranges, int left, int right) {
    int[] seen = new int[52];

    for (int[] range : ranges) {
      ++seen[range[0]];
      --seen[range[1] + 1];
    }

    for (int i = 1; i < 52; ++i)
      seen[i] += seen[i - 1];

    for (int i = left; i <= right; ++i)
      if (seen[i] == 0)
        return false;

    return true;
  }
}
