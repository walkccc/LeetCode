class Solution {
  public int hardestWorker(int n, int[][] logs) {
    int ans = logs[0][0];
    int maxWorkingTime = logs[0][1];

    for (int i = 1; i < logs.length; ++i) {
      final int id = logs[i][0];
      final int workingTime = logs[i][1] - logs[i - 1][1];
      if (workingTime > maxWorkingTime) {
        ans = id;
        maxWorkingTime = workingTime;
      } else if (workingTime == maxWorkingTime) {
        ans = Math.min(ans, id);
      }
    }

    return ans;
  }
}
