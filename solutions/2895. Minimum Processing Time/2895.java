class Solution {
  public int minProcessingTime(List<Integer> processorTime, List<Integer> tasks) {
    int ans = 0;
    Collections.sort(processorTime);
    Collections.sort(tasks, Collections.reverseOrder());

    // It's optimal to run each 4 longer tasks with a smaller processor time.
    // Therefore, for each processor, take the maximum of the sum of the
    // processor time and the largest assigned tasks[i].
    for (int i = 0; i < processorTime.size(); ++i)
      ans = Math.max(ans, processorTime.get(i) + tasks.get(i * 4));

    return ans;
  }
}
