class Solution {
  public int[] getModifiedArray(int length, int[][] updates) {
    int[] ans = new int[length];
    int prefixSum = 0;

    for (final int[] update : updates) {
      final int startIndex = update[0];
      final int endIndex = update[1];
      final int inc = update[2];
      ans[startIndex] += inc;
      if (endIndex + 1 < length)
        ans[endIndex + 1] -= inc;
    }

    for (int i = 0; i < length; ++i) {
      prefixSum += ans[i];
      ans[i] = prefixSum;
    }

    return ans;
  }
}