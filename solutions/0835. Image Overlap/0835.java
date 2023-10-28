class Solution {
  public int largestOverlap(int[][] A, int[][] B) {
    final int n = A.length;
    final int magic = 100;
    int ans = 0;
    List<int[]> onesA = new ArrayList<>();
    List<int[]> onesB = new ArrayList<>();
    Map<Integer, Integer> map = new HashMap<>();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (A[i][j] == 1)
          onesA.add(new int[] {i, j});
        if (B[i][j] == 1)
          onesB.add(new int[] {i, j});
      }

    for (int[] a : onesA)
      for (int[] b : onesB) {
        final int key = (a[0] - b[0]) * magic + a[1] - b[1];
        map.merge(key, 1, Integer::sum);
      }

    for (final int value : map.values())
      ans = Math.max(ans, value);

    return ans;
  }
}
