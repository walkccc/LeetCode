class UF {
  public UF(int n) {
    id = new int[n + 1];
    for (int i = 0; i < id.length; ++i)
      id[i] = i;
  }

  public void union(int u, int v) {
    id[find(u)] = find(v);
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
}

class Solution {
  public int largestComponentSize(int[] A) {
    final int n = Arrays.stream(A).max().getAsInt();
    int ans = 0;
    UF uf = new UF(n);
    Map<Integer, Integer> count = new HashMap<>();

    for (int a : A)
      for (int num = 2; num <= (int) Math.sqrt(a); ++num)
        if (a % num == 0) {
          uf.union(a, num);
          uf.union(a, a / num);
        }

    for (int a : A) {
      int pa = uf.find(a);
      count.put(pa, count.getOrDefault(pa, 0) + 1);
      ans = Math.max(ans, count.get(pa));
    }

    return ans;
  }
}
