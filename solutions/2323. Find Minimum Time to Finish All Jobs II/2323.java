class Solution {
  public int minimumTime(int[] jobs, int[] workers) {
    int ans = 0;

    Arrays.sort(jobs);
    Arrays.sort(workers);

    for (int i = 0; i < jobs.length; ++i)
      ans = Math.max(ans, (jobs[i] - 1) / workers[i] + 1);

    return ans;
  }
}
