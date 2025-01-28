class Solution {
  // Same as 3318. Find X-Sum of All K-Long Subarrays I
  public long[] findXSum(int[] nums, int k, int x) {
    long[] ans = new long[nums.length - k + 1];
    Map<Integer, Integer> count = new HashMap<>();
    TreeSet<Pair<Integer, Integer>> top =
        new TreeSet<>((a, b)
                          -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                                           : a.getKey().compareTo(b.getKey()));
    TreeSet<Pair<Integer, Integer>> bot =
        new TreeSet<>((a, b)
                          -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                                           : a.getKey().compareTo(b.getKey()));

    for (int i = 0; i < nums.length; ++i) {
      update(nums[i], 1, count, top, bot);
      if (i >= k)
        update(nums[i - k], -1, count, top, bot);
      // Move the bottom elements to the top if needed.
      while (!bot.isEmpty() && top.size() < x) {
        Pair<Integer, Integer> pair = bot.pollLast();
        top.add(pair);
        windowSum += (long) pair.getValue() * pair.getKey();
      }
      // Swap the bottom and top elements if needed.
      while (!bot.isEmpty() && (bot.last().getKey() > top.first().getKey() ||
                                bot.last().getKey().equals(top.first().getKey()) &&
                                    bot.last().getValue() > top.first().getValue())) {
        Pair<Integer, Integer> pairB = bot.pollLast();
        Pair<Integer, Integer> pairT = top.pollFirst();
        top.add(pairB);
        bot.add(pairT);
        windowSum += (long) pairB.getValue() * pairB.getKey();
        windowSum -= (long) pairT.getValue() * pairT.getKey();
      }
      if (i >= k - 1)
        ans[i - k + 1] = windowSum;
    }
    return ans;
  }

  private long windowSum = 0;

  // Updates the count of num by freq and the window sum accordingly.
  private void update(int num, int freq, Map<Integer, Integer> count,
                      TreeSet<Pair<Integer, Integer>> top, TreeSet<Pair<Integer, Integer>> bot) {
    if (count.getOrDefault(num, 0) > 0) { // Clean up the old count.
      Pair<Integer, Integer> pair = new Pair<>(count.get(num), num);
      if (bot.remove(pair)) {
        // Do nothing.
      } else {
        top.remove(pair);
        windowSum -= (long) num * count.get(num);
      }
    }
    count.merge(num, freq, Integer::sum);
    if (count.get(num) > 0)
      bot.add(new Pair<>(count.get(num), num));
  }
}
