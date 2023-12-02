class Solution {
  public int minFlips(int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;
    final int hash = getHash(mat, m, n);
    if (hash == 0)
      return 0;

    final int[] dirs = {0, 1, 0, -1, 0};
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(hash));
    Set<Integer> seen = new HashSet<>(Arrays.asList(hash));

    for (int step = 1; !q.isEmpty(); ++step) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int curr = q.poll();
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            int next = curr ^ 1 << (i * n + j);
            // Flie the four neighbors.
            for (int k = 0; k < 4; ++k) {
              final int x = i + dirs[k];
              final int y = j + dirs[k + 1];
              if (x < 0 || x == m || y < 0 || y == n)
                continue;
              next ^= 1 << (x * n + y);
            }
            if (next == 0)
              return step;
            if (seen.contains(next))
              continue;
            q.offer(next);
            seen.add(next);
          }
        }
      }
    }

    return -1;
  }

  private int getHash(int[][] mat, int m, int n) {
    int hash = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 1)
          hash |= 1 << (i * n + j);
    return hash;
  }
}
