class UnionFind {
  public void unionByRank(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    if (rank.get(i) < rank.get(j)) {
      id.put(i, j);
    } else if (rank.get(i) > rank.get(j)) {
      id.put(j, i);
    } else {
      id.put(i, j);
      rank.merge(j, 1, Integer::sum);
    }
  }

  public int find(int u) {
    if (!id.containsKey(u)) {
      id.put(u, u);
      rank.put(u, 0);
    }
    if (id.get(u) != u)
      id.put(u, find(id.get(u)));
    return id.get(u);
  }

  private Map<Integer, Integer> id = new HashMap<>();
  private Map<Integer, Integer> rank = new HashMap<>();
}

class Solution {
  public int countComponents(int[] nums, int threshold) {
    UnionFind uf = new UnionFind();

    for (final int num : nums)
      for (int multiple = 2 * num; multiple <= threshold; multiple += num)
        uf.unionByRank(num, multiple);

    return Arrays.stream(nums).map(uf::find).boxed().collect(Collectors.toSet()).size();
  }
}
