class Solution {
  public int[] getModifiedArray(int length, int[][] updates) {
    int[] ans = new int[length];
    int[] line = new int[length];
    int prefix = 0;

    for (int[] update : updates) {
      final int startIndex = update[0];
      final int endIndex = update[1];
      final int inc = update[2];
      line[startIndex] += inc;
      if (endIndex + 1 < length)
        line[endIndex + 1] -= inc;
    }

    for (int i = 0; i < length; ++i) {
      prefix += line[i];
      ans[i] = prefix;
    }

    return ans;
  }
}
