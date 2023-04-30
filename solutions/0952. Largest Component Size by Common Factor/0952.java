class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void unionByRank(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = id[j];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
    } else {
      id[i] = id[j];
      ++rank[j];
    }
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
  private int[] rank;
}

class Solution {
  public int largestComponentSize(int[] nums) {
    final int n = Arrays.stream(nums).max().getAsInt();
    int ans = 0;
    UnionFind uf = new UnionFind(n + 1);
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      for (int x = 2; x <= (int) Math.sqrt(num); ++x)
        if (num % x == 0) {
          uf.unionByRank(num, x);
          uf.unionByRank(num, num / x);
        }

    for (final int num : nums) {
      final int numRoot = uf.find(num);
      count.merge(numRoot, 1, Integer::sum);
      ans = Math.max(ans, count.get(numRoot));
    }

    return ans;
  }
}
