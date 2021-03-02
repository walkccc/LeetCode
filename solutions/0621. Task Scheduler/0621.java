class Solution {
  public int leastInterval(char[] tasks, int n) {
    int[] count = new int[26];

    for (final char task : tasks)
      ++count[task - 'A'];

    final int maxFreq = Arrays.stream(count).max().getAsInt();
    // put the most frequent task in the slot first
    final int maxTaskOccupy = (maxFreq - 1) * (n + 1);
    // get # of tasks with same frequency as maxFreq,
    // we'll append them after maxTaskOccupy
    final int nMaxFreq = (int) Arrays.stream(count).filter(c -> c == maxFreq).count();

    // max(
    //   the most frequent task is frequent enough to force some idle slots,
    //   the most frequent task is not frequent enough to force idle slots
    // )
    return Math.max(maxTaskOccupy + nMaxFreq, tasks.length);
  }
}
