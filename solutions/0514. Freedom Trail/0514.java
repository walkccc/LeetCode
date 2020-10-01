class Solution {
  public int findRotateSteps(String ring, String key) {
    Map<String, Integer> memo = new HashMap<>();
    return dfs(ring, key, 0, memo) + key.length();
  }

  private int dfs(final String ring, final String key, int index, Map<String, Integer> memo) {
    if (index == key.length())
      return 0;
    final String hashKey = ring + index;
    if (memo.containsKey(hashKey))
      return memo.get(hashKey);

    int ans = Integer.MAX_VALUE;

    for (int i = 0; i < ring.length(); ++i)
      if (ring.charAt(i) == key.charAt(index)) {
        int diff = Math.min(i, ring.length() - i);
        int step = dfs(ring.substring(i) + ring.substring(0, i), key, index + 1, memo);
        ans = Math.min(ans, diff + step);
      }

    memo.put(hashKey, ans);
    return ans;
  }
}