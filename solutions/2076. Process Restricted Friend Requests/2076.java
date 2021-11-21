class UF {
  public UF(int n) {
    parent = new int[n];
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  public void union(int pu, int pv) {
    parent[pu] = pv;
  }

  public int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  private int[] parent;
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
