class Solution {
  public long taskSchedulerII(int[] tasks, int space) {
    Map<Integer, Long> taskToNextAvailable = new HashMap<>();
    long ans = 0;

    for (final int task : tasks) {
      ans = Math.max(ans + 1, taskToNextAvailable.getOrDefault(task, 0L));
      taskToNextAvailable.put(task, ans + space + 1);
    }

    return ans;
  }
}
