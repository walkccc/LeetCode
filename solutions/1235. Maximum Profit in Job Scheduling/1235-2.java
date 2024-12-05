class Solution {
  public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
    record Job(int startTime, int endTime, int profit) {}
    final int n = startTime.length;
    // dp[i] := the maximum profit to schedule jobs[i..n)
    int[] dp = new int[n + 1];
    Job[] jobs = new Job[n];

    for (int i = 0; i < n; ++i)
      jobs[i] = new Job(startTime[i], endTime[i], profit[i]);

    Arrays.sort(jobs, (a, b) -> Integer.compare(a.startTime, b.startTime));

    for (int i = 0; i < n; ++i)
      startTime[i] = jobs[i].startTime;

    for (int i = n - 1; i >= 0; --i) {
      final int j = firstGreaterEqual(startTime, i + 1, jobs[i].endTime);
      final int pick = jobs[i].profit + dp[j];
      final int skip = dp[i + 1];
      dp[i] = Math.max(pick, skip);
    }

    return dp[0];
  }

  private int firstGreaterEqual(int[] A, int startFrom, int target) {
    int l = startFrom;
    int r = A.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if (A[m] >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
