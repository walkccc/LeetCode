class Solution {
  public boolean isCovered(int[][] ranges, int left, int right) {
    for (int i = left; i <= right; ++i) {
      boolean seen = false;
      for (int[] range : ranges)
        if (i >= range[0] && i <= range[1]) {
          seen = true;
          break;
        }
      if (!seen)
        return false;
    }

    return true;
  }
}
