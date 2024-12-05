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
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
  }

  public boolean connected(int u, int v) {
    return find(u) == find(v);
  }

  public void reset(int u) {
    id[u] = u;
  }

  private int[] id;
  private int[] rank;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
    List<Integer> ans = new ArrayList<>();
    UnionFind uf = new UnionFind(n);
    TreeMap<Integer, List<Pair<Integer, Integer>>> timeToPairs = new TreeMap<>();

    uf.unionByRank(0, firstPerson);

    for (int[] m : meetings) {
      timeToPairs.putIfAbsent(m[2], new ArrayList<>());
      timeToPairs.get(m[2]).add(new Pair<>(m[0], m[1]));
    }

    for (List<Pair<Integer, Integer>> pairs : timeToPairs.values()) {
      Set<Integer> peopleUnioned = new HashSet<>();
      for (Pair<Integer, Integer> pair : pairs) {
        final int x = pair.getKey();
        final int y = pair.getValue();
        uf.unionByRank(x, y);
        peopleUnioned.add(x);
        peopleUnioned.add(y);
      }
      for (final int person : peopleUnioned)
        if (!uf.connected(person, 0))
          uf.reset(person);
    }

    for (int i = 0; i < n; ++i)
      if (uf.connected(i, 0))
        ans.add(i);

    return ans;
  }
}
