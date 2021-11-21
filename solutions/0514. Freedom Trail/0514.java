class Solution {
  public int findRotateSteps(String ring, String key) {
    Map<String, Integer> memo = new HashMap<>();
    return dfs(ring, key, 0, memo) + key.length();
  }

  // # of rotates of ring to match key[index:]
  private int dfs(final String ring, final String key, int index, Map<String, Integer> memo) {
    if (index == key.length())
      return 0;
    // add the index to prevent duplicate
    final String hashKey = ring + index;
    if (memo.containsKey(hashKey))
      return memo.get(hashKey);

    int ans = Integer.MAX_VALUE;

    // for each ring[i] == key[index]
    // we rotate the ring to match ring[i] w/ key[index]
    // then recursively match newRing w/ key[index + 1:]
    for (int i = 0; i < ring.length(); ++i)
      if (ring.charAt(i) == key.charAt(index)) {
        final int minRotates = Math.min(i, ring.length() - i);
        final String newRing = ring.substring(i) + ring.substring(0, i);
        final int remainingRotates = dfs(newRing, key, index + 1, memo);
        ans = Math.min(ans, minRotates + remainingRotates);
      }

    memo.put(hashKey, ans);
    return ans;
  }
}
