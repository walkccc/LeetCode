class UF {
  public int[] id;

  public UF(int n) {
    id = new int[n];
    Arrays.fill(id, -1); // water
  }

  public void union(int u, int v) {
    id[u] = v;
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public List<Integer> numIslands2(int m, int n, int[][] positions) {
    final int[] dirs = {0, 1, 0, -1, 0};
    List<Integer> ans = new ArrayList<>();
    boolean[][] seen = new boolean[m][n];
    UF uf = new UF(m * n);
    int count = 0;

    for (int[] p : positions) {
      final int i = p[0];
      final int j = p[1];
      if (seen[i][j]) {
        ans.add(count);
        continue;
      }
      seen[i][j] = true;
      final int id = getId(i, j, n);
      uf.id[id] = id;
      ++count;
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        final int neighborId = getId(x, y, n);
        if (uf.id[neighborId] == -1) // water
          continue;
        final int currentParent = uf.find(id);
        final int neighborParent = uf.find(neighborId);
        if (currentParent != neighborParent) {
          uf.union(currentParent, neighborParent);
          --count;
        }
      }
      ans.add(count);
    }

    return ans;
  }

  private int getId(int i, int j, int n) {
    return i * n + j;
  }
}
