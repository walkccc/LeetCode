class Solution {
  public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
    List<int[]> ans = new ArrayList<>();
    final int[] dx = {1, 0, -1, 0};
    final int[] dy = {0, 1, 0, -1};

    ans.add(new int[] {r0, c0});

    for (int i = 0; ans.size() < R * C; ++i)
      for (int step = 0; step < i / 2 + 1; ++step) {
        r0 += dy[i % 4];
        c0 += dx[i % 4];
        if (0 <= r0 && r0 < R && 0 <= c0 && c0 < C)
          ans.add(new int[] {r0, c0});
      }

    return ans.toArray(new int[ans.size()][]);
  }
}
