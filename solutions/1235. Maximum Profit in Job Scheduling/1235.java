class Solution {
  public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
    final int n = startTime.length;
    int[] mem = new int[n + 1];
    Job[] jobs = new Job[n];

    for (int i = 0; i < n; ++i)
      jobs[i] = new Job(startTime[i], endTime[i], profit[i]);

    Arrays.sort(jobs, Comparator.comparingInt(Job::startTime));

    // Will use binary search to find the first available start time.
    for (int i = 0; i < n; ++i)
      startTime[i] = jobs[i].startTime;

    return jobScheduling(jobs, startTime, 0, mem);
  }

  private record Job(int startTime, int endTime, int profit) {}

  private int jobScheduling(Job[] jobs, int[] startTime, int i, int[] mem) {
    if (i == jobs.length)
      return 0;
    if (mem[i] > 0)
      return mem[i];

    final int j = firstGreaterEqual(startTime, i + 1, jobs[i].endTime);
    final int pick = jobs[i].profit + jobScheduling(jobs, startTime, j, mem);
    final int skip = jobScheduling(jobs, startTime, i + 1, mem);
    return mem[i] = Math.max(pick, skip);
  }

  private int firstGreaterEqual(int[] arr, int startFrom, int target) {
    int l = startFrom;
    int r = arr.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if (arr[m] >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
