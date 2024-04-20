class Solution {
  public boolean isNStraightHand(int[] hand, int groupSize) {
    TreeMap<Integer, Integer> count = new TreeMap<>();

    for (final int card : hand)
      count.merge(card, 1, Integer::sum);

    for (final int start : count.keySet()) {
      final int value = count.getOrDefault(start, 0);
      if (value > 0)
        for (int i = start; i < start + groupSize; ++i)
          if (count.merge(i, -value, Integer::sum) < 0)
            return false;
    }

    return true;
  }
}
