class Solution {
  public int leastInterval(char[] tasks, int n) {
    int[] count = new int[26];

    for (char task : tasks)
      ++count[task - 'A'];

    final int maxCount = Arrays.stream(count).max().getAsInt();
    int ans = (maxCount - 1) * (n + 1);

    for (int c : count)
      if (c == maxCount)
        ++ans;

    return Math.max(ans, tasks.length);
  }
}