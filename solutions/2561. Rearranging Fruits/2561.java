class Solution {
  public long minCost(int[] basket1, int[] basket2) {
    long ans = 0;
    List<Integer> swapped = new ArrayList<>();
    Map<Integer, Integer> count = new HashMap<>();

    for (final int b : basket1)
      count.merge(b, 1, Integer::sum);

    for (final int b : basket2)
      count.merge(b, -1, Integer::sum);

    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      final Integer num = entry.getKey();
      final Integer freq = entry.getValue();
      if (freq % 2 != 0)
        return -1;
      for (int i = 0; i < Math.abs(freq) / 2; ++i)
        swapped.add(num);
    }

    final int minNum =
        Math.min(Arrays.stream(basket1).min().getAsInt(), Arrays.stream(basket2).min().getAsInt());
    Collections.sort(swapped);

    for (int i = 0; i < swapped.size() / 2; ++i)
      ans += Math.min(minNum * 2, swapped.get(i));
    return ans;
  }
}
