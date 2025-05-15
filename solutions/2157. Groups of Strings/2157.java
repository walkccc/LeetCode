class UnionFind {
  public UnionFind(int n) {
    count = n;
    id = new int[n];
    sz = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
    for (int i = 0; i < n; ++i)
      sz[i] = 1;
  }

  public void unionBySize(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    if (sz[i] < sz[j]) {
      sz[j] += sz[i];
      id[i] = j;
    } else {
      sz[i] += sz[j];
      id[j] = i;
    }
    --count;
  }

  public int getCount() {
    return count;
  }

  public int getMaxSize() {
    return Arrays.stream(sz).max().getAsInt();
  }

  private int count;
  private int[] id;
  private int[] sz;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public int[] groupStrings(String[] words) {
    UnionFind uf = new UnionFind(words.length);
    Map<Integer, Integer> maskToIndex = new HashMap<>();
    Map<Integer, Integer> deletedMaskToIndex = new HashMap<>();

    for (int i = 0; i < words.length; ++i) {
      final int mask = getMask(words[i]);
      for (int j = 0; j < 26; ++j)
        if ((mask >> j & 1) == 1) {
          // Going to delete this bit.
          final int m = mask ^ 1 << j;
          if (maskToIndex.containsKey(m))
            uf.unionBySize(i, maskToIndex.get(m));
          if (deletedMaskToIndex.containsKey(m))
            uf.unionBySize(i, deletedMaskToIndex.get(m));
          else
            deletedMaskToIndex.put(m, i);
        } else {
          // Going to add this bit.
          final int m = mask | 1 << j;
          if (maskToIndex.containsKey(m))
            uf.unionBySize(i, maskToIndex.get(m));
        }
      maskToIndex.put(mask, i);
    }

    return new int[] {uf.getCount(), uf.getMaxSize()};
  }

  private int getMask(final String s) {
    int mask = 0;
    for (final char c : s.toCharArray())
      mask |= 1 << c - 'a';
    return mask;
  }
}
