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

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
  private int[] rank;
}

class Solution {
  public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
    StringBuilder sb = new StringBuilder();
    UnionFind uf = new UnionFind(s.length());
    Map<Integer, Queue<Character>> indexToLetters = new HashMap<>();

    for (List<Integer> pair : pairs) {
      final int a = pair.get(0);
      final int b = pair.get(1);
      uf.unionByRank(a, b);
    }

    for (int i = 0; i < s.length(); ++i)
      indexToLetters.computeIfAbsent(uf.find(i), k -> new PriorityQueue<>()).offer(s.charAt(i));

    for (int i = 0; i < s.length(); ++i)
      sb.append(indexToLetters.get(uf.find(i)).poll());

    return sb.toString();
  }
}
