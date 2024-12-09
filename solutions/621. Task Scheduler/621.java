class Solution {
  public int leastInterval(char[] tasks, int n) {
    int[] count = new int[26];

    for (final char task : tasks)
      ++count[task - 'A'];

    final int maxFreq = Arrays.stream(count).max().getAsInt();
    // Put the most frequent task in the slot first.
    final int maxFreqTaskOccupy = (maxFreq - 1) * (n + 1);
    // Get the number of tasks with the same frequency as `maxFreq`, we'll
    // append them after `maxFreqTaskOccupy`.
    final int nMaxFreq = (int) Arrays.stream(count).filter(c -> c == maxFreq).count();
    // max(
    //   the most frequent task is frequent enough to force some idle slots,
    //   the most frequent task is not frequent enough to force idle slots
    // )
    return Math.max(maxFreqTaskOccupy + nMaxFreq, tasks.length);
  }
}
