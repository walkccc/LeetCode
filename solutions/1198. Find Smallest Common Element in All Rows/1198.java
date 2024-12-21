class Solution {
  public int smallestCommonElement(int[][] mat) {
    final int kMax = 10000;
    int[] count = new int[kMax + 1];

    for (int[] row : mat)
      for (final int a : row)
        if (++count[a] == mat.length)
          return a;

    return -1;
  }
}
