class Solution {
  public int findMinimumTime(int[][] tasks) {
    final int kMax = 2000;
    boolean[] running = new boolean[kMax + 1];

    // Sort tasks by end.
    Arrays.sort(tasks, (a, b) -> Integer.compare(a[1], b[1]));

    for (int[] task : tasks) {
      final int start = task[0];
      final int end = task[1];
      final int duration = task[2];
      int neededDuration = duration;
      for (int i = start; i <= end; ++i)
        if (running[i])
          --neededDuration;
      // Greedily run the task as late as possible so that later tasks can run
      // simultaneously.
      for (int i = end; neededDuration > 0; --i) {
        if (!running[i]) {
          running[i] = true;
          --neededDuration;
        }
      }
    }

    return (int) IntStream.range(0, running.length)
        .mapToObj(i -> running[i])
        .filter(r -> r)
        .count();
  }
}
