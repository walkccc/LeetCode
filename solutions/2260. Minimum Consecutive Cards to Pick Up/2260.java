class Solution {
  public int minimumCardPickup(int[] cards) {
    int ans = Integer.MAX_VALUE;
    Map<Integer, Integer> lastOccurrence = new HashMap<>();

    for (int i = 0; i < cards.length; ++i) {
      if (lastOccurrence.containsKey(cards[i]))
        ans = Math.min(ans, i - lastOccurrence.get(cards[i]) + 1);
      lastOccurrence.put(cards[i], i);
    }

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
