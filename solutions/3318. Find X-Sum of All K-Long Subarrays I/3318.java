class Solution {
  public int[] findXSum(int[] nums, int k, int x) {
    int[] ans = new int[nums.length - k + 1];
    Map<Integer, Integer> count = new HashMap<>();
    TreeSet<Pair<Integer, Integer>> top =
        new TreeSet<>(Comparator.comparingInt(Pair<Integer, Integer>::getKey)
                          .thenComparingInt(Pair<Integer, Integer>::getValue));
    TreeSet<Pair<Integer, Integer>> bot =
        new TreeSet<>(Comparator.comparingInt(Pair<Integer, Integer>::getKey)
                          .thenComparingInt(Pair<Integer, Integer>::getValue));

    for (int i = 0; i < nums.length; ++i) {
      update(nums[i], 1, count, top, bot);
      if (i >= k)
        update(nums[i - k], -1, count, top, bot);
      // Move the bottom elements to the top if needed.
      while (!bot.isEmpty() && top.size() < x) {
        Pair<Integer, Integer> pair = bot.pollLast();
        top.add(pair);
        windowSum += pair.getValue() * pair.getKey();
      }
      // Swap the bottom and top elements if needed.
      while (!bot.isEmpty() && (bot.last().getKey() > top.first().getKey() ||
                                bot.last().getKey().equals(top.first().getKey()) &&
                                    bot.last().getValue() > top.first().getValue())) {
        Pair<Integer, Integer> pairB = bot.pollLast();
        Pair<Integer, Integer> pairT = top.pollFirst();
        top.add(pairB);
        bot.add(pairT);
        windowSum += pairB.getValue() * pairB.getKey();
        windowSum -= pairT.getValue() * pairT.getKey();
      }
      if (i >= k - 1)
        ans[i - k + 1] = windowSum;
    }
    return ans;
  }

  private int windowSum = 0;

  // Updates the count of num by freq and the window sum accordingly.
  private void update(int num, int freq, Map<Integer, Integer> count,
                      TreeSet<Pair<Integer, Integer>> top, TreeSet<Pair<Integer, Integer>> bot) {
    if (count.getOrDefault(num, 0) > 0) { // Clean up the old count.
      Pair<Integer, Integer> pair = new Pair<>(count.get(num), num);
      if (bot.remove(pair)) {
        // Do nothing.
      } else {
        top.remove(pair);
        windowSum -= num * count.get(num);
      }
    }
    count.merge(num, freq, Integer::sum);
    if (count.get(num) > 0)
      bot.add(new Pair<>(count.get(num), num));
  }
}
