class Solution {
  public int largestOverlap(int[][] img1, int[][] img2) {
    final int kMagic = 100;
    final int n = img1.length;
    int ans = 0;
    List<int[]> ones1 = new ArrayList<>();
    List<int[]> ones2 = new ArrayList<>();
    Map<Integer, Integer> offsetCount = new HashMap<>();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (img1[i][j] == 1)
          ones1.add(new int[] {i, j});
        if (img2[i][j] == 1)
          ones2.add(new int[] {i, j});
      }

    for (int[] a : ones1)
      for (int[] b : ones2) {
        final int key = (a[0] - b[0]) * kMagic + a[1] - b[1];
        offsetCount.merge(key, 1, Integer::sum);
      }

    for (final int count : offsetCount.values())
      ans = Math.max(ans, count);

    return ans;
  }
}
