class Solution {
  public int findRotateSteps(String ring, String key) {
    Map<String, Integer> mem = new HashMap<>();
    return dfs(ring, key, 0, mem) + key.length();
  }

  // Returns the number of rotates of ring to match key[index..n).
  private int dfs(final String ring, final String key, int index, Map<String, Integer> mem) {
    if (index == key.length())
      return 0;
    // Add the index to prevent duplication.
    final String hashKey = ring + index;
    if (mem.containsKey(hashKey))
      return mem.get(hashKey);

    int ans = Integer.MAX_VALUE;

    // For each ring[i] == key[index], we rotate the ring to match the ring[i]
    // with the key[index], then recursively match the newRing with the
    // key[index + 1..n).
    for (int i = 0; i < ring.length(); ++i)
      if (ring.charAt(i) == key.charAt(index)) {
        final int minRotates = Math.min(i, ring.length() - i);
        final String newRing = ring.substring(i) + ring.substring(0, i);
        final int remainingRotates = dfs(newRing, key, index + 1, mem);
        ans = Math.min(ans, minRotates + remainingRotates);
      }

    mem.put(hashKey, ans);
    return ans;
  }
}
