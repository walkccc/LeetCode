class UF {
  public UF(int n) {
    count = n;
    id = new int[n];
    size = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
    for (int i = 0; i < n; ++i)
      size[i] = 1;
  }

  public void union(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = id[j];
      size[j] += size[i];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
      size[i] += size[j];
    } else {
      id[i] = id[j];
      size[j] += size[i];
      ++rank[j];
    }
    --count;
  }

  public int getCount() {
    return count;
  }

  public int getMaxSize() {
    return Arrays.stream(size).max().getAsInt();
  }

  private int count;
  private int[] id;
  private int[] size;
  private int[] rank;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public int[] groupStrings(String[] words) {
    UF uf = new UF(words.length);
    Map<Integer, Integer> maskToIndex = new HashMap<>();
    Map<Integer, Integer> deletedMaskToIndex = new HashMap<>();

    for (int i = 0; i < words.length; ++i) {
      final int mask = getMask(words[i]);
      for (int j = 0; j < 26; ++j)
        if ((mask >> j & 1) == 1) {
          // going to delete this bit
          final int m = mask ^ 1 << j;
          if (maskToIndex.containsKey(m))
            uf.union(i, maskToIndex.get(m));
          if (deletedMaskToIndex.containsKey(m))
            uf.union(i, deletedMaskToIndex.get(m));
          else
            deletedMaskToIndex.put(m, i);
        } else {
          // going to add this bit
          final int m = mask | 1 << j;
          if (maskToIndex.containsKey(m))
            uf.union(i, maskToIndex.get(m));
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
