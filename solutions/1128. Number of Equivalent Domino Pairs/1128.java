class Solution {
  public int numEquivDominoPairs(int[][] dominoes) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int[] domino : dominoes) {
      int key = Math.min(domino[0], domino[1]) * 10 + Math.max(domino[0], domino[1]);
      ans += count.getOrDefault(key, 0);
      count.put(key, count.getOrDefault(key, 0) + 1);
    }

    return ans;
  }
}
