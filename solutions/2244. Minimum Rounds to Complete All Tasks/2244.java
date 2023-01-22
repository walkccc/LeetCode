class Solution {
  public int minimumRounds(int[] tasks) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int task : tasks)
      count.merge(task, 1, Integer::sum);

    // Freq = 1 -> impossible
    // Freq = 2 -> needs 1 round
    // Freq = 3 -> needs 1 round
    // Freq = 3k                           -> needs k rounds
    // Freq = 3k + 1 = 3 * (k - 1) + 2 * 2 -> needs k + 1 rounds
    // Freq = 3k + 2 = 3 * k       + 2 * 1 -> needs k + 1 rounds
    for (final int freq : count.values())
      if (freq == 1)
        return -1;
      else
        ans += (freq + 2) / 3;

    return ans;
  }
}
