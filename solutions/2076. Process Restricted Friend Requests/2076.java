class UF {
  public UF(int n) {
    id = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void union(int u, int v) {
    id[u] = v;
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
}

class Solution {
  public boolean[] friendRequests(int n, int[][] restrictions, int[][] requests) {
    boolean[] ans = new boolean[requests.length];
    UF uf = new UF(n);

    for (int i = 0; i < requests.length; ++i) {
      final int pu = uf.find(requests[i][0]);
      final int pv = uf.find(requests[i][1]);
      boolean isValid = true;
      if (pu != pv)
        for (int[] restriction : restrictions) {
          final int px = uf.find(restriction[0]);
          final int py = uf.find(restriction[1]);
          if (pu == px && pv == py || pu == py && pv == px) {
            isValid = false;
            break;
          }
        }
      ans[i] = isValid;
      if (isValid)
        uf.union(pu, pv);
    }

    return ans;
  }
}
