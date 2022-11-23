class Solution {
  public boolean isNStraightHand(int[] hand, int W) {
    TreeMap<Integer, Integer> count = new TreeMap<>();

    for (final int card : hand)
      count.put(card, count.getOrDefault(card, 0) + 1);

    for (final int start : count.keySet()) {
      final int value = count.getOrDefault(start, 0);
      if (value > 0)
        for (int i = start; i < start + W; ++i) {
          count.put(i, count.getOrDefault(i, 0) - value);
          if (count.get(i) < 0)
            return false;
        }
    }

    return true;
  }
}
