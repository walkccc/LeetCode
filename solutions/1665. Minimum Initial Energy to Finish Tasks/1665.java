class Solution {
  public int minimumEffort(int[][] tasks) {
    int ans = 0;
    int prevSaved = 0;

    Arrays.sort(tasks, Comparator.comparingInt(task -> task[0] - task[1]));

    for (int[] task : tasks) {
      final int actual = task[0];
      final int minimum = task[1];
      if (prevSaved < minimum) {
        ans += minimum - prevSaved;
        prevSaved = minimum - actual;
      } else {
        prevSaved -= actual;
      }
    }

    return ans;
  }
}
