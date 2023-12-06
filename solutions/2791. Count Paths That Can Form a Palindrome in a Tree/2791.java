class Solution {
  public long countPalindromePaths(List<Integer> parent, String s) {
    // A valid (u, v) has at most 1 letter with odd frequency on its path. The
    // frequency of a letter on the u-v path is equal to the sum of its
    // frequencies on the root-u and root-v paths substract twice of its
    // frequency on the root-LCA(u, v) path. Considering only the parity
    // (even/odd), the part involving root-LCA(u, v) can be ignored, making it
    // possible to calculate both parts easily using a simple DFS.
    List<Integer>[] tree = new List[parent.size()];

    for (int i = 0; i < parent.size(); ++i)
      tree[i] = new ArrayList<>();

    for (int i = 1; i < parent.size(); ++i)
      tree[parent.get(i)].add(i);

    return dfs(tree, 0, 0, s, new HashMap<>(Map.of(0, 1)));
  }

  // mask := 26 bits that represent the parity of each character in the alphabet
  // on the path from node 0 to node u
  private long dfs(List<Integer>[] tree, int u, int mask, String s,
                   Map<Integer, Integer> maskToCount) {
    long res = 0;
    if (u > 0) {
      mask ^= 1 << (s.charAt(u) - 'a');
      // Consider any u-v path with 1 bit set.
      for (int i = 0; i < 26; ++i)
        if (maskToCount.containsKey(mask ^ (1 << i)))
          res += maskToCount.get(mask ^ (1 << i));
      // Consider u-v path with 0 bit set.
      res += maskToCount.getOrDefault(mask ^ 0, 0);
      maskToCount.merge(mask, 1, Integer::sum);
    }
    for (final int v : tree[u])
      res += dfs(tree, v, mask, s, maskToCount);
    return res;
  }
}
