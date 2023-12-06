class Job {
  public int startTime;
  public int endTime;
  public int profit;
  public Job(int startTime, int endTime, int profit) {
    this.startTime = startTime;
    this.endTime = endTime;
    this.profit = profit;
  }
}

class Solution {
  public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
    final int n = startTime.length;
    // dp[i] := the maximum profit to schedule jobs[i..n)
    dp = new int[n + 1];
    Job[] jobs = new Job[n];

    for (int i = 0; i < n; ++i)
      jobs[i] = new Job(startTime[i], endTime[i], profit[i]);

    Arrays.sort(jobs, (a, b) -> a.startTime - b.startTime);

    // Will use binary search to find the first available startTime
    for (int i = 0; i < n; ++i)
      startTime[i] = jobs[i].startTime;

    return jobScheduling(jobs, startTime, 0);
  }

  private int[] dp;

  private int jobScheduling(Job[] jobs, int[] startTime, int i) {
    if (i == jobs.length)
      return 0;
    if (dp[i] > 0)
      return dp[i];

    final int j = firstGreaterEqual(startTime, i + 1, jobs[i].endTime);
    final int pick = jobs[i].profit + jobScheduling(jobs, startTime, j);
    final int skip = jobScheduling(jobs, startTime, i + 1);
    return dp[i] = Math.max(pick, skip);
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
