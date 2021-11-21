class Solution {
  public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
    StringBuilder ans = new StringBuilder();
    UF uf = new UF(s.length());
    Map<Integer, PriorityQueue<Character>> map = new HashMap<>();

    for (List<Integer> pair : pairs)
      uf.union(pair.get(0), pair.get(1));

    for (int i = 0; i < s.length(); ++i)
      map.computeIfAbsent(uf.find(i), k -> new PriorityQueue<>()).offer(s.charAt(i));

    for (int i = 0; i < s.length(); ++i)
      ans.append(map.get(uf.find(i)).poll());

    return ans.toString();
  }

  private class UF {
    private int[] size;
    private int[] id;

    private UF(int n) {
      size = new int[n];
      id = new int[n];
      for (int i = 0; i < n; ++i) {
        size[i] = 1;
        id[i] = i;
      }
    }

    private void union(int p, int q) {
      int i = find(p);
      int j = find(q);
      if (i == j)
        return;
      if (size[i] < size[j]) {
        id[i] = j;
        size[j] += size[i];
      } else {
        id[j] = i;
        size[i] += size[j];
      }
    }

    private int find(int i) {
      while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
      }
      return i;
    }
  }
}
