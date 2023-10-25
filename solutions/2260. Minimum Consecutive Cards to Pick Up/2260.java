class Solution {
  public int minimumCardPickup(int[] cards) {
    int ans = Integer.MAX_VALUE;
    Map<Integer, Integer> lastSeen = new HashMap<>();

    for (int i = 0; i < cards.length; ++i) {
      if (lastSeen.containsKey(cards[i]))
        ans = Math.min(ans, i - lastSeen.get(cards[i]) + 1);
      lastSeen.put(cards[i], i);
    }

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
